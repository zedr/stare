typedef enum {true, false} bool;

struct config {
	bool verbose;
	char *what;
	char *cmd;
	bool is_valid;
};
