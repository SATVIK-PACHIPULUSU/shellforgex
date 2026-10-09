#ifndef PARSER_H
#define PARSER_H

void parse_command(char *input, char *args[], int max_args);
int split_pipeline(char *input, char *commands[], int max_commands);

#endif
