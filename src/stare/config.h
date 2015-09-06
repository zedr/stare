struct config *get_config(int argc, const char *argv[]);
bool is_valid_config(struct config *conf);
void print_config(struct config *conf);

struct config {
	bool verbose;
	char *what;
	char *cmd;
	bool is_valid;
};