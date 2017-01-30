#include "Request.h"

Request::Request()
{
	//struct MemoryStruct chunk;

	//chunk.memory = (char*) malloc(1);  /* will be grown as needed by the realloc above */
	//chunk.size = 0;    /* no data at this point */

	//curl_global_init(CURL_GLOBAL_ALL);

	curl = curl_easy_init();
	if (curl) {
		curl_slist_append(headers, "Accept: application/json");
		curl_slist_append(headers, "Content-Type: application/json");
		curl_slist_append(headers, "charsets: utf-8");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

		curl_easy_setopt(curl, CURLOPT_URL, "https://awesome.sdsc.edu:18002/query?query=use+dataverse+newsPaper%3B%0D%0Afor+%24i+in+dataset(%27news%27)%0D%0Aorder+by+%24i.date+%0D%0Awhere+%24i.date+%3D+1325462400000%0D%0Areturn+%7B+%0D%0A++++%22ArticleId%22%3A+%24i.articleId%2C%0D%0A++++%22Content%22+%3A+%24i.content%0D%0A+++++++++++%7D");
		
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
	//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &WriteMemoryCallback);

	//	/* we pass our 'chunk' struct to the callback function */
	//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);


		/* Perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if (res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
				curl_easy_strerror(res));


		/* always cleanup */
		curl_easy_cleanup(curl);

	//	printf("%lu bytes retrieved\n", (long)chunk.size);
	//	free(chunk.memory);
	}
}
//
//size_t Request::Write(void *ptr, size_t size, size_t nmemb, void *stream)
//{
//	rawResponse.append((char*)ptr, size*nmemb);
//	cout << rawResponse << endl;
//	return size*nmemb;
//}
//
//size_t Request::WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
//{
//	size_t realsize = size * nmemb;
//	struct MemoryStruct *mem = (struct MemoryStruct *)userp;
//
//	mem->memory = (char*)realloc(mem->memory, mem->size + realsize + 1);
//	if (mem->memory == NULL) {
//		/* out of memory! */
//		printf("not enough memory (realloc returned NULL)\n");
//		return 0;
//	}
//
//	memcpy(&(mem->memory[mem->size]), contents, realsize);
//	mem->size += realsize;
//	mem->memory[mem->size] = 0;
//
//	return realsize;
//}