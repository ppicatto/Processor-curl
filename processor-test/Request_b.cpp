#include "Request_b.h"

Request_b::Request_b()
{
	const std::string url("http://date.jsontest.com/");

	CURL* curl = curl_easy_init();

	// Set remote URL.
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

	// Don't bother trying IPv6, which would increase DNS resolution time.
	curl_easy_setopt(curl, CURLOPT_IPRESOLVE, CURL_IPRESOLVE_V4);

	// Don't wait forever, time out after 10 seconds.
	curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

	// Follow HTTP redirects if necessary.
	curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

	// Response information.
	int httpCode(0);
	std::unique_ptr<std::string> httpData(new std::string());

	// Hook up data handling function.
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, &Request_b::writer);

	// Hook up data container (will be passed as the last parameter to the
	// callback handling function).  Can be any pointer type, since it will
	// internally be passed as a void pointer.
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, httpData.get());

	// Run our HTTP GET command, capture the HTTP response code, and clean up.
	curl_easy_perform(curl);
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);
	curl_easy_cleanup(curl);

	if (httpCode == 200)
	{
		std::cout << "\nGot successful response from " << url << std::endl;

		// Response looks good - done using Curl now.  Try to parse the results
		// and print them out.
		std::cout << *httpData << std::endl;

	}
	else
	{
		std::cout << "Couldn't GET from " << url << " - exiting" << std::endl;
	}
}

int Request_b::writer(char *data, size_t size, size_t nmemb, std::string *buffer_in)
{

	// Is there anything in the buffer?  
	if (buffer_in != NULL)
	{
		// Append the data to the buffer    
		buffer_in->append(data, size * nmemb);

		// How much did we write?   
		DownloadedResponse = buffer_in;

		return size * nmemb;
	}

	return 0;

}