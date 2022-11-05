#include "pch.h"
#include "LibcurlHttp.h"

struct MemoryStruct {
    char* memory;
    size_t size;
};

static size_t
WriteMemoryCallback(void* contents, size_t size, size_t nmemb, void* userp)
{
    size_t realsize = size * nmemb;
    struct MemoryStruct* mem = (struct MemoryStruct*)userp;

    char* ptr = (char*)realloc(mem->memory, mem->size + realsize + 1);
    if (!ptr) {
        /* out of memory! */
        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }

    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

LibcurlHttp::LibcurlHttp() :headers_list_(NULL) {}

bool LibcurlHttp::HttpRequest(std::string url, std::string &response, bool get, std::string postdata) {
	CURL* curl;
	CURLcode res;
	struct MemoryStruct chunk;
    bool ret = 0;

    chunk.memory = (char*)malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        if (!get) {
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postdata.c_str());
            curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(postdata.c_str()));
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
            curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "");
        }
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers_list_);

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)&chunk);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/106.0.0.0 Safari/537.36");
        res = curl_easy_perform(curl);
        ret = !(bool)res;
        if (res != CURLE_OK) {
            //fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }
        else {
            response = chunk.memory;
        }
        curl_easy_cleanup(curl);
    }
    free(chunk.memory);
    curl_global_cleanup();
    return ret;
}

void LibcurlHttp::AppendHeadersList(std::string header) {
    headers_list_ = curl_slist_append(headers_list_, header.c_str());
}
