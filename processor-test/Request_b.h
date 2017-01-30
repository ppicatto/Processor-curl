
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <curl/curl.h>

class Request_b
{

	public:
		Request_b();
		int writer(char *data, size_t size, size_t nmemb, std::string *buffer_in);
		std::string *DownloadedResponse;
		size_t callback(
			const char* in,
			std::size_t size,
			std::size_t num,
			std::string* out)
		{
			const std::size_t totalBytes(size * num);
			out->append(in, totalBytes);
			return totalBytes;
		}
};

