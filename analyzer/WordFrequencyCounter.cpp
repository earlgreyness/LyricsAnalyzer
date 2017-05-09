#include "WordFrequencyCounter.h"
#include <qDebug>
#include <QFileDialog>
#include <QString>
#include <QtAlgorithms>

WordFrequencyCounter::WordFrequencyCounter()
{
    QString word("");
    QFile ignoredWordsFile("service_words.txt");
    if (ignoredWordsFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&ignoredWordsFile);
        QString symbol;
        symbol.resize(1);
        while (!stream.atEnd())
        {
            symbol = stream.read(1);
            if (symbol.at(0).isLetter())
            {
                word.append(symbol.at(0).toLower());
            }
            else if (!word.isEmpty())
            {
                this->ignoredWordsList.append(word);
                //qDebug() << word;
                word.clear();
            }

        }
        ignoredWordsFile.close();
    }
    qDebug() << ignoredWordsList;


    QString nameOfTheFile = QFileDialog::getOpenFileName();
    this->analyzeFile(nameOfTheFile);
}

void WordFrequencyCounter::addWordToDictionary(const QString& word)
{
    if (!this->ignoredWordsList.contains(word))
    {
        if (this->dictionary.contains(word))
        {
            ++dictionary[word];
        }
        else
        {
            this->dictionary.insert(word, 1);
        }
    }

}

void WordFrequencyCounter::analyzeFile(const QString& fileName)
{
    QString word("");
    QFile inputFile(fileName);
    if (inputFile.open(QIODevice::ReadOnly))
    {
        QTextStream stream(&inputFile);
        QString symbol;
        symbol.resize(1);
        while (!stream.atEnd())
        {
            symbol = stream.read(1);
            if (symbol.at(0).isLetter())
            {
                word.append(symbol.at(0).toLower());
            }
            else if (!word.isEmpty())
            {
                this->addWordToDictionary(word);
                //qDebug() << word;
                word.clear();
            }

        }
        inputFile.close();
    }
}

bool sortCriteria(const QPair<QString, qint32> & p1, const QPair<QString, qint32> & p2)
{
    return p1.second > p2.second;
}


void WordFrequencyCounter::printResults()
{
    QList< QPair< QString, qint32 > > sortedDictionary;
    QPair<QString, qint32> temp;

    DictType::iterator it = this->dictionary.begin();

    for (; it != this->dictionary.end(); ++it)
    {
        temp.first = it.key();
        temp.second = it.value();
        sortedDictionary.append(temp);
    }

    qSort(sortedDictionary.begin(), sortedDictionary.end(), sortCriteria);

   // QList< QPair< QString, qint32 > >::iterator it2 = sortedDictionary.begin();
   // for (int i = 0; i < sortedDictionary.size(); ++i)
  //  {
  //      qDebug() << "[" << sortedDictionary.at(i).second << "] " << sortedDictionary.at(i).first;
  //  }

   QFile outputFile("output.txt");
   if (outputFile.open(QIODevice::WriteOnly))
   {
       QTextStream stream(&outputFile);
       for (int i = 0; i < sortedDictionary.size(); ++i)
       {
           stream << i + 1 << ". " << sortedDictionary.at(i).first << " [" << sortedDictionary.at(i).second << "]\n";
       }
       outputFile.close();

       if (stream.status() != QTextStream::Ok)
       {
           qDebug() << "Error writing output file";
       }
   }

   qDebug() << "Writing output file successfully finished";

}



