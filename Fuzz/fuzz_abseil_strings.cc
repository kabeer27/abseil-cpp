#include <string>

#include "../absl/strings/str_join.h"
#include "../absl/strings/str_split.h"
#include "../absl/strings/numbers.h"
#include "../absl/strings/str_cat.h"


extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	size_t min_length = 13 * sizeof()
	std::string str (reinterpret_cast<const char*>(data), size);
	std::vector<std::string> v = absl::StrSplit(str, ',');
	str = absl::StrJoin(v, ",");

	return 0;
}