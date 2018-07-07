// utility functions for working with directories

#include <fsutil>


// CreateDirIfNotExists creates a directory if it does not already exist.
CreateDirIfNotExists(directory[]) {
	if(!Exists(directory)) {
		CreateDir(directory);
	}
}
