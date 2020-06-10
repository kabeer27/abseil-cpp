#include <string> 

#include "../absl/strings/escaping.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
	std::string str (reinterpret_cast<const char*>(data), size);
	std::string escaped, unescaped;
	escaped = absl::CHexEscape(str);
	absl::CUnescape(escaped, &unescaped);
	
	escaped = absl::CEscape(str);
	absl::CUnescape(escaped, &unescaped);
	
	escaped = absl::CUtf8SafeEscape(str);
	abs::CUnescape(escaped, &unescaped);
	
	escaped = absl::Utf8SafeCHexEscape(str);
	abs::Unescape(escaped, &unescaped);
	
	std::string encoded, decoded;
	abs::Base64Escape(str, &encoded);
	abs::Base64Unescape(encoded, &decoded);

	absl::WebSafeBase64Escape(str, &encoded);
	absl::WebSafeBase64UnEscape(encoded, &decoded);

	std::string hex_result, bytes_result;
	hex_result = absl::BytesToHexString(str);
	bytes_result = absl::HexStringToBytes(hex_result);

	return 0;
}