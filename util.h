#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <QDesktopWidget>
#include <QtGui>

using namespace std;

#define TIMEOUT 3000

string exec(string);
int atoi(string);
int weightToIndex(string);
QColor stringToHex(string);
string orMap(map<string, string>, map<string, string>, string key);
string itos(int);
string normalizeString(QString);
