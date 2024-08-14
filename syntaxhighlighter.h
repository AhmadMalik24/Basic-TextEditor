#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>

#include <QRegularExpression>
#include <QList>



class SyntaxHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    SyntaxHighlighter(QTextDocument *parent = nullptr);

protected:
    void highlightBlock(const QString &text) override; //function inherited from QsyntaxHighlighter class it call itself

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QList<HighlightingRule> highlightingRules;

    QTextCharFormat keywordFormat;
    QTextCharFormat stdFunctionFormat; // for cin cout etc
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat includeFormat;
    QTextCharFormat preprocessorFormat;
    QTextCharFormat angleBracketFormat;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat openingBracketFormat;
    QTextCharFormat closingBracketFormat;
    QTextCharFormat missingBracketFormat;
};

#endif
