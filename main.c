#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
#define min 512

void help() {
  printf("touch *Name of File* -- Used to make Files");
  printf("\nremove *Name of File* -- Used to Remove Files");
  printf("\nlist -- Listing Files");
  printf("\nfind -- Used for Finding Files");
  printf("\nexit -- Used to quit");
}

void make_file(char arg[])
{
    FILE *f;
    f = fopen(arg,"w");
    fclose(f);
    free(f);
}

int main() {
  // Make Variable to Store Initial Input
  char input[max];
  // Make post parse storage Variables (P.S.V)
  char command[min];
  char arg[min];
  // wrapping the whole thing in a while loop
  while (1) {
    // Basic Shell Prompt
    printf("\n> ");
    // Taking Initial Input
    fgets(input, max, stdin);

    // To remove newline from fgets
    // input[strspn(input, "\n")] = '\0';

    // Parsing input
    sscanf(input, "%[a-zA-z] %[a-zA-Z]", command, arg);

    // If Conditions
    if ((strcmp(command, "touch")) == 0) {
            make_file(arg);
            printf("m!");
    } else if ((strcmp(command, "remove")) == 0) {
      printf("remove!");
    } else if ((strcmp(command, "list")) == 0) {
      printf("l!");
    } else if ((strcmp(command, "find")) == 0) {
      printf("f!");
    } else if ((strcmp(command, "exit")) == 0) {
      printf("Exiting...");
      break;
    } else if ((strcmp(command, "Help")) == 0) {
      help();
    }
    else {
      printf("Invalid Try Again. Type \"Help\" if you need Command List");
    }
  }
  return 0;
}
