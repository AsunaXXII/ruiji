#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"

#define ESHUUSHUU_URL "http://e-shuushuu.net"
#define ESHUUSHUU_SOURCE_ID "<a class=\"thumb_image\" href=\""

/* Given a http://e-shuushuu.net url,
 * parse the html to get the source image url
 */
char* eshuushuu_get_image_url(char *html_content)
{
	/* Find the source image link */
	char *source_index = strstr(html_content, ESHUUSHUU_SOURCE_ID);
	char *img_src_url = "\0";

	/* If found, add the website url to it and return it */
	if (source_index) {
		/* move source_index pointer to the beginning of
		 * the source image url */
		source_index = &source_index[strlen(ESHUUSHUU_SOURCE_ID)];
		unsigned int url_len = get_distance(source_index, '"');

		/* allocate enough memory to hold the image source url,
		 * then copy the url over to img_src_url and return it */
		img_src_url = malloc(sizeof(char) *
					(url_len + strlen(ESHUUSHUU_URL) + 1));
		img_src_url[0] = '\0';
		strcat(img_src_url, ESHUUSHUU_URL);
		strncat(img_src_url, source_index, url_len);
	}
	else
		printf("eshuushuu_get_image_url(): Error: Failed to parse website\n");

	/* return the image source url */
	return img_src_url;
}
