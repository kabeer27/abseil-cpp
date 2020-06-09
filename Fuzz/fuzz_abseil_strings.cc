#include <string>

#include "../absl/strings/str_join.h"
#include "../absl/strings/str_split.h"

int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	std::string str(reinterpret_cast<const char*>(data), size);
	std::vector<std::string> v = absl::StrSplit(str, ',');
	std::string str = absl::StrJoin(v, "-");

	return 0;
}