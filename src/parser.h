/* struct for storing html content */
struct html_data {
	char *data;
	size_t size;
};

/* struct representing a similar image to a parent image */
struct similar_image {
	char *link;
	unsigned int similarity;
	unsigned int dimensions[2];
};

/* struct representing a database of similar images
 * all to the same parent image.
 */
struct similar_image_db {
	struct similar_image *img_db[16];
	unsigned int size;
};


size_t StoreData(char *contents, size_t size, size_t nmemb, struct html_data *userp);

/* Replace the first instance of find with replace,
 * mutating the string.
 */
void replace_first_with(char *string, char find, char replace);

/* Given the necessary information of a similar image, create a similar image
 * struct with the given values and return it.
 */
struct similar_image *create_sim_image(char *url_begin, unsigned int similarity, unsigned int x, unsigned int y);

/* Given the html contents of http://iqdb.org after an image has been uploaded,
 * get the x, y dimensions of the image and return a pointer pointing to the
 * html contents where the parsing stopped.
 */
char *parse_percent_similar(char *contents, unsigned int *similarity);

/* Given the html contents of http://iqdb.org after an image has been uploaded,
 * get the x, y dimensions of the image and return a pointer pointing to the
 * html contents where the parsing stopped.
 */
char *parse_xy_img_dimensions(char* contents, unsigned int *x, unsigned int *y);

/* Given the html contents of http://iqdb.org after an image has been uploaded,
 * parse all the results and store them in the struct similar_image_db *sim_db
 */
void populate_sim_db(struct similar_image_db *sim_db, char *html_content);


struct similar_image *get_most_similar_image(struct similar_image_db *sim_db);

/* Given the full link of a website,
 * fetch and return the html source of the website
 */
char *get_html(char *web_url);

/* Given the full link of a website,
 * parse the link to get the file name
 */
char *get_server_file_name(char *web_url, char stop);

char *get_image_url(char *web_url, char *trademark, char* prefix, char suffix);


/* Frees the allocated memory for a similar_image_db */
void free_similar_image_db(struct similar_image_db *sim_db);
