#ifndef get_next_line_h
# define get_next_line_h
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>

char	*ft_substr(char  *s, unsigned int start, size_t len);
char	*ft_strjoin(char  *s1, char  *s2);
size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
char	*ft_strchr( char *s, int c);
char	*ft_strdup( char *src);
#endif