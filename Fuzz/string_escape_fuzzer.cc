#include <string> 

#include "../absl/strings/escaping.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	std::string str (reinterpret_cast<const char*>(data), size);
	std::string escaped = absl::CHexEscape(str);
	std::string unescaped;
	absl::CUnescape(escaped, &unescaped);
	return 0;
}