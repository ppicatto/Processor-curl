#include <curl\curl.h>
#include <iostream>
#include <string>

using namespace std;

class Request
{
	CURL *curl;
	CURLcode res;
	struct curl_slist *headers = NULL;

	//struct MemoryStruct {
	//	char *memory;
	//	size_t size;
	//};

	///**
	//* @var string response from get request
	//*/
	std::string rawResponse;

	///**
	//* @var string url to request
	//*/
	string queryStringParam = "use+dataverse+newsPaper%3B%0D%0Afor+%24i+in+dataset(%27news%27)%0D%0Aorder+by+%24i.date+%0D%0Awhere+%24i.date+%3D+1325462400000%0D%0Areturn+%7B+%0D%0A++++\"ArticleId\"%3A+%24i.articleId%2C%0D%0A++++\"Content\"+%3A+%24i.content%0D%0A+++++++++++%7D";

	///**
	//* @var string url to request
	//*/
	//string url = "https://awesome.sdsc.edu:18002/query?query=";

	public:
		Request();
	//	size_t Write(void *ptr, size_t size, size_t nmemb, void *stream);
	//	size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp);

};

