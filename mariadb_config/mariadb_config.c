#include <my_global.h>
#include <my_sys.h>
#include <getopt.h>
#include <stdio.h>

#define INCLUDE "-I/usr/local/include/mariadb"
#define LIBS    "-L/usr/local/lib/mariadb -lmariadb" \
                " -lpthread -lssl -ldl -lm"
#define CFLAGS  INCLUDE " -Wunused -Wno-uninitialized"
#define VERSION "5.5.0"
#define SOCKET  "/tmp/mysql.sock"
#define PORT "3306"

static struct option long_options[]=
{
  {"cflags", no_argument, 0, 'a'},
  {"help", no_argument, 0, 'b'},
  {"include", no_argument, 0, 'c'},
  {"libs", no_argument, 0, 'd'},
  {"libs_r", no_argument, 0, 'e'},
  {"version", no_argument, 0, 'f'},
  {"socket", no_argument, 0, 'g'},
  {"port", no_argument, 0, 'h'},
  {NULL, 0, 0, 0}
};

static char *values[]=
{
  CFLAGS,
  NULL,
  INCLUDE,
  LIBS,
  LIBS,
  VERSION,
  SOCKET,
  PORT
};
  
void usage(void)
{
  int i=0;
  puts("Copyright 2011 Monty Program AB");
  puts("Get compiler flags for using the MariaDB client library.");
  printf("Usage: %s [OPTIONS]\n", my_progname);
  while (long_options[i].name)
  {
    if (values[i])
      printf("  --%-12s  [%s]\n", long_options[i].name, values[i]);
    i++;
  }
}


int main(int argc, char **argv)
{
  int c;
  my_progname= argv[0];

  if (argc <= 1)
  {
    usage();
    exit(1);
  }

  while(1)
  {
    int option_index= 0;
    c= getopt_long(argc, argv, "abcdef", long_options, &option_index);

    switch(c) {
    case 'a':
      puts(CFLAGS);
      break;
    case 'b':
      usage();
      break;
    case 'c':
      puts(INCLUDE);
      break;
    case 'd':
    case 'e':
      puts(LIBS);
      break;
    case 'f':
      puts(VERSION);
      break;
    case 'g':
      puts(SOCKET);
      break;
    case 'h':
      puts(PORT);
      break;
    default:
      exit(0);
    }
  }

  exit(0);
}

