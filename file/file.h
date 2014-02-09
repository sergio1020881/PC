/***MY OBJECT***/
struct ficheiro{
	//Local Variables
	FILE *fp;
	char filename[128];
	char permision[8];

	//Local Function pointers
	char* (*ftos)(FILE* stream);
	char* (*fltos)(FILE* stream);
	int (*strtotok)(char* line,char* token[],const char* parser);
	int (*close)(struct ficheiro *f);
	FILE* (*open)(struct ficheiro *f);
};
typedef struct ficheiro file;
file filecreate(char *filename);
/***readconsole***/
char* FILEreadconsole(FILE* stream);
