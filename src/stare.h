#define EVENT_SIZE (sizeof (struct inotify_event))
#define BUF_LEN	(1024 * (EVENT_SIZE + 16))

typedef enum {true, false} bool;

struct config {
	bool verbose;
	char *what;
	char *cmd;
	bool is_valid;
};
