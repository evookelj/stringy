#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int stringlen(char s[]) {
  int i = 0;
  while (*s) {
    i++;
    s++;
  }
  return i;
}

char* stringcpy(char *dest, char *src) {
  int i;
  for (i=0; src[i] != '\0'; i++) {
    dest[i] = src[i];
  }
}

char* stringncpy(char *dest, char *src, int n) {
  int i;

  for (i = 0; i < n && src[i] != '\0'; i++)
    dest[i] = src[i];
  for ( ; i < n; i++)
    dest[i] = '\0';
  return dest;
}

char* stringcat(char *dest, char *src) {
  int i;
  int dest_len = stringlen(dest);

  for (i=0; src[i] != '\0'; i++) { dest[dest_len + i] = src[i]; }
  dest[dest_len + i] = '\0';
  return dest;
}

char* stringncat(char *dest, char *src, int n) {
  int i;
  int dest_len = strlen(dest);

  for (i=0; (i<n) && (src[i] != '\0'); i++) { dest[dest_len+i] = src[i]; }
  dest[dest_len+i] = '\0';
  return dest;
}

//N to self: fix to not take into account length unless same
int stringcmp(char *s1, char *s2) {
  int i;
  if (stringlen(s1) > stringlen(s2)) { return 1; }
  else if (stringlen(s1) < stringlen(s2)) { return -1; }
  for (i=0; i<strlen(s1); i++) {
    if (s1[i] > s2[i]) { return 1; }
    if (s1[i] < s2[i]) { return -1; }
  }
  return 0;
}

char* stringchr(char *s, char c) {
  int i;
  for (i=0; i<strlen(s); i++) {
    if (s[i] == c) { return &(s[i]); }
  }
  return NULL;
}

int main() {
  char s1[] = "Freaks";
  char s2[] = "Geeks";
  printf("Before applying functions:\ns1=%s, length=%d\ns2=%s, length=%d\n\n", s1, stringlen(s1), s2, stringlen(s2));

  stringcpy(s2, s1);
  printf("Testing stringcpy:\nstringcpy(s2,s1): s2=%s, length=%d\n\n", s2, stringlen(s2));

  stringcat(s2,"And");
  printf("Testing stringcat:\nCat \"And\" to s2: s2=%s, length=%d\n", s2, stringlen(s2));
  printf("s1=%s, length=%d\n\n", s1, stringlen(s1));
  
  stringncpy(s2, s1, 1);
  printf("Testing stringncpy:\nstringncpy(s2, s1, 1): s2=%s, length=%d\n\n", s2, stringlen(s2));


  stringncat(s1, "GeeksHa", 3);
  printf("Testing stringncat:\nstringncat(s1,\"Geeks\"): s1=%s, length=%d\n\n", s1, stringlen(s1));
  

  printf("Testing stringcmp:\ncompare ab to abc: %d\ncompare abc to ab: %d\ncompare abc to abc: %d\n\n", stringcmp("ab","abc"), stringcmp("abc","ab"), stringcmp("abc","abc"));
    
  printf("Testing strchr:\nstrchr(\"Sam\", \'a\'): [%c]\nstrchr(\"Lindsay\", \'e\': [%c]\n", *(stringchr("Sam",'a')), stringchr("Lindsay", 'e'));
}
