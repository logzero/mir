static char *read_file (const char *name) {
  FILE *f;
  size_t len, rlen;
  char *str;

  if ((f = fopen (name, "r")) == NULL) {
    perror (name);
    exit (1);
  }
  fseek (f, 0, SEEK_END);
  len = ftell (f);
  rewind (f);
  str = (char *) malloc (len + 1);
  rlen = fread (str, 1, len, f)
#ifndef _MSC_VER
  if (rlen != len) {
    fprintf (stderr, "file %s was changed\n", name);
    free (str);
    exit (1);
  }
#endif
  str[rlen] = 0;
  return str;
}
