#include <cstdio>
#include <unistd.h>
#include <vector>

int main(int argc, char ** argv) {
  std::vector<char *> newargv;
  char stdarg[] = "-std=gnu++11";
  for (int i = 0; i < argc; ++i) {
    newargv.push_back(argv[i]);
    if (i == 0)
      newargv.push_back(stdarg);
  }
  newargv.push_back(stdarg);
  newargv.push_back((char*)nullptr);
  for (char * arg : newargv)
    printf("%s\n", arg ? arg : "(nil)");
  execv("/usr/bin/g++", &newargv[0]);
  return 0;
}
