// Response requires installment of libraries like libcurl4-openssl-dev and nlohmann/json3-dev, 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

struct Article {
    string name;
    int comments;
};

size_t writeData(void *ptr, size_t size, size_t nmemb, string *data) {
    data->append((char *)ptr, size * nmemb);
    return size * nmemb;
}

bool sortArticles(const Article& a, const Article& b) {
    if (a.comments != b.comments) {
        return a.comments > b.comments;
    }

    return a.name > b.name;
}

vector<string> topArticles(int limit) {
    vector<Article> articles;

    int page = 1;
    int total_pages = 1;

    while (page <= total_pages) {
        string response;
        string url = "https://jsonmock.hackerrank.com/api/articles?page=" + to_string(page);

        CURL *curl = curl_easy_init();

        if (curl != NULL) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

            CURLcode res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if (res == CURLE_OK) {
                json data = json::parse(response);

                total_pages = data["total_pages"];

                for (int i = 0; i < data["data"].size(); i++) {
                    json item = data["data"][i];

                    string name = "";

                    if (!item["title"].is_null()) {
                        name = item["title"];
                    } else if (!item["story_title"].is_null()) {
                        name = item["story_title"];
                    }

                    if (name != "") {
                        int comments = 0;

                        if (!item["num_comments"].is_null()) {
                            comments = item["num_comments"];
                        }

                        Article article;
                        article.name = name;
                        article.comments = comments;

                        articles.push_back(article);
                    }
                }
            }
        }

        page++;
    }

    sort(articles.begin(), articles.end(), sortArticles);

    vector<string> ans;

    for (int i = 0; i < limit && i < articles.size(); i++) {
        ans.push_back(articles[i].name);
    }

    return ans;
}