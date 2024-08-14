#include "syntaxhighlighter.h"
#include <QTextDocument>
#include <QStack>
#include <QMap>

SyntaxHighlighter::SyntaxHighlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    // Helper lambda to add rules
    auto addRule = [this](const QString &pattern, const QTextCharFormat &format) {
        HighlightingRule rule;
        rule.pattern = QRegularExpression(pattern);
        rule.format = format;
        highlightingRules.append(rule);
    };

    // Bracket formats
    openingBracketFormat.setForeground(Qt::yellow);
    closingBracketFormat.setForeground(Qt::yellow);
    missingBracketFormat.setForeground(Qt::gray);

    // Keyword format
    keywordFormat.setForeground(QColor(135, 186, 250));

    const QStringList keywordPatterns = {
        "\\bclass\\b", "\\bconst\\b", "\\bvirtual\\b", "\\bvoid\\b", "\\bint\\b", "\\bchar\\b",
        "\\bif\\b", "\\belse\\b", "\\bfor\\b", "\\bwhile\\b", "\\bbreak\\b", "\\bcontinue\\b",
        "\\breturn\\b", "\\bpublic\\b", "\\bprivate\\b", "\\bprotected\\b", "\\bnamespace\\b",
        "\\busing\\b", "\\bstatic\\b", "\\bstruct\\b", "\\btypedef\\b", "\\btemplate\\b",
        "\\btypename\\b", "\\bnew\\b", "\\bdelete\\b", "\\bfriend\\b", "\\binline\\b",
        "\\blong\\b", "\\bshort\\b", "\\bsigned\\b", "\\bunsigned\\b", "\\bbool\\b",
        "\\btrue\\b", "\\bfalse\\b", "\\bthis\\b", "\\bsizeof\\b"
    };

    for (const QString &pattern : std::as_const(keywordPatterns)) {
        addRule(pattern, keywordFormat);
    }

    // Standard library functions format
    stdFunctionFormat.setForeground(Qt::yellow);
    const QStringList stdFunctionPatterns = {
        "\\bstd::cout\\b", "\\bstd::cin\\b", "\\bstd::cerr\\b", "\\bcin\\b", "\\bcout\\b"
    };

    for (const QString &pattern : std::as_const(stdFunctionPatterns)) {
        addRule(pattern, stdFunctionFormat);
    }

    // Class format
    classFormat.setFontWeight(QFont::Bold);
    classFormat.setForeground(Qt::darkMagenta);
    addRule("\\bQ[A-Za-z]+\\b", classFormat);

    // Preprocessor directive format
    preprocessorFormat.setForeground(Qt::darkBlue);
    addRule("^\\s*#\\s*\\w+", preprocessorFormat);

    // Include statement format
    includeFormat.setForeground(Qt::darkBlue);
    addRule("#include\\s*<[^>]+>", includeFormat);

    // Single-line comment format
    singleLineCommentFormat.setForeground(Qt::darkGreen);
    addRule("//[^\n]*", singleLineCommentFormat);

    // Multi-line comment format (no direct rule addition, handled in `highlightBlock`)
    multiLineCommentFormat.setForeground(Qt::darkGreen);
    commentStartExpression = QRegularExpression("/\\*");
    commentEndExpression = QRegularExpression("\\*/");

    // Quotation format
    quotationFormat.setForeground(Qt::darkGreen);
    addRule("\".*\"", quotationFormat);
    addRule("'.*'", quotationFormat);

    // Angle bracket format
    angleBracketFormat.setForeground(Qt::darkGreen);
    addRule("<[^>]+>", angleBracketFormat);

    // Function format
    functionFormat.setFontItalic(true);
    functionFormat.setForeground(Qt::blue);
    addRule("\\b[A-Za-z0-9_]+(?=\\()", functionFormat);
}


void SyntaxHighlighter::highlightBlock(const QString &text)
{
    // Early exit if the line is empty
    if (text.isEmpty()) {
        return;
    }

    // Apply syntax highlighting rules
    for (const HighlightingRule &rule : std::as_const(highlightingRules)) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }

    setCurrentBlockState(0);

    int startIndex = (previousBlockState() != 1) ? commentStartExpression.match(text).capturedStart() : 0;

    while (startIndex >= 0) {
        QRegularExpressionMatch match = commentEndExpression.match(text, startIndex);
        int endIndex = match.capturedStart();
        int commentLength;

        if (endIndex == -1) {
            setCurrentBlockState(1);  // Comment continues in the next block
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex + match.capturedLength();
        }

        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.match(text, startIndex + commentLength).capturedStart();
    }

    //---------------------------------------------------------------------------

    QStack<int> bracketStack;


    for (int i = 0; i < text.length(); ++i) {
        QChar currentChar = text[i];

        // Handle opening brackets
        if (currentChar == '{' || currentChar == '(' || currentChar == '[') {
            bracketStack.push(i);
        }
        // Handle closing brackets
        else if (currentChar == '}' || currentChar == ')' || currentChar == ']') {
            if (!bracketStack.isEmpty()) {
                int openingPos = bracketStack.pop();
                QChar openingChar = text[openingPos];

                // Check if the brackets match
                if ((currentChar == '}' && openingChar == '{') ||
                    (currentChar == ')' && openingChar == '(') ||
                    (currentChar == ']' && openingChar == '[')) {
                    // Highlight matching brackets
                    setFormat(openingPos, 1, openingBracketFormat);
                    setFormat(i, 1, closingBracketFormat);
                } else {
                    // Highlight mismatched brackets
                    setFormat(openingPos, 1, missingBracketFormat);
                    setFormat(i, 1, missingBracketFormat);
                }
            } else {
                // Highlight unmatched closing bracket
                setFormat(i, 1, missingBracketFormat);
            }
        }
    }

    // Any unmatched opening brackets left in the stack
    while (!bracketStack.isEmpty()) {
        int openingPos = bracketStack.pop();
        setFormat(openingPos, 1, missingBracketFormat);
    }


}


