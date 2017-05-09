#ifndef WORDFREQUENCYCOUNTER_H
#define WORDFREQUENCYCOUNTER_H


#include <QMap>
#include <QString>
#include <QFile>
#include <QPair>
#include <QStringList>

typedef QMap<QString, qint32> DictType;

//
class WordFrequencyCounter
{
public:
    WordFrequencyCounter();


private:
    DictType dictionary;
    QStringList ignoredWordsList;


    void analyzeFile(const QString& fileName);
    void addWordToDictionary(const QString& word);
   // bool sortCriteria(const QPair<QString, qint32> & p1, const QPair<QString, qint32> & p2);



public:
    void printResults();
};

#endif // WORDFREQUENCYCOUNTER_H
