#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 

int main(int argc, char *argv[]) {
  // Flush after every printf
  setbuf(stdout, NULL);
  
  while(1){
    
    printf("$ ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strcmp(input, "exit")==0){
      break;
    } else if (strncmp(input, "echo ", 5) == 0) {
      printf("%s\n", input + 5);} 

      else if (strncmp(input, "type ", 5) == 0) {char *arg = input +5;
      if (!strcmp(arg, "exit") || !strcmp(arg, "type") || !strcmp(arg, "echo")) 
      {printf("%s is a shell builtin\n", arg);} 

      else { 
        
         
        char path_copy[1000]; 
        strcpy(path_copy, getenv("PATH")); 

        char *dir = strtok(path_copy, ":"); 
        int found = 0;

        while (dir != NULL) {
          char full_path[500];
          snprintf(full_path, sizeof(full_path), "%s/%s", dir, arg);  
        
        if (access(full_path, X_OK) == 0) {
        printf("%s is %s\n", arg, full_path);
        found = 1; 
        break; 
        }

        dir = strtok(NULL, ":");
      }

      if (!found){
        printf("%s: not found\n", arg);
      }
    }
  }
      
  else {printf("%s: command not found\n", input);} }
     
    

  return 0;
}