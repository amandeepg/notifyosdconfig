#include "util.h"

string exec(string cmd) {
  FILE* pipe = popen(cmd.c_str(), "r");
  if (!pipe) return "ERROR";
  char buffer[128];
  string result = "";
  while(!feof(pipe)) {
    if(fgets(buffer, 128, pipe) != NULL)
      result += buffer;
  }
  pclose(pipe);
  return result;
}

int atoi(string s) {
  return atoi(s.c_str());
}

int weightToIndex(string s) {
  if (s == "normal") {
    return 1;
  } else if (s == "light") {
    return 2;
  } else {
    return 0;
  }
}

QColor stringToHex(string s) {
  return QColor(("#" + s).c_str());
}

string orMap(map<string, string> map1, map<string, string> map2, string key) {
  if (map1.find(key) != map1.end()) {
    return map1[key];
  } else {
    return map2[key];
  }
}

string itos(int i) {
  stringstream s;
  s << i;
  return s.str();
}

string normalizeString(QString s) {
  return s.toLower().remove("#").remove(" ").toStdString();
}
