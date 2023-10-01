
#include <iostream>
#include "WebServer.hpp"

void printTreeStructure(MultiTreeNode* node, int depth = 0);

// TODO For test
int main(void)
{
	// atexit(leak);

	std::cout << "http block size: " << sizeof(HttpBlock) << std::endl;
	std::cout << "server block size: " << sizeof(ServerBlock) << std::endl;
	std::cout << "location block size: " << sizeof(LocationBlock) << std::endl;

	WebServer* inst = WebServer::GetInstance();
	const HttpBlock* config = inst->GetHttp();
	// ParseFile("nginx.conf", *config);
	printTreeStructure(config->root.at(0)->GetRoot());
	printTreeStructure(config->root.at(1)->GetRoot());
	printTreeStructure(config->serverList.at(0)->root.at(0)->GetRoot());
	printTreeStructure(config->serverList.at(1)->root.at(0)->GetRoot());
	printSearchedResult(*config->root.at(0), "/404.html/");
	printSearchedResult(*config->root.at(0), "/404.html/src");
	printSearchedResult(*config->root.at(0), "/404.html/src/something");
	printSearchedResult(*config->root.at(1), "/50x.html/");
	printSearchedResult(*config->root.at(1), "/50x.html/something");
	printSearchedResult(*config->serverList.at(0)->root.at(0), "/1/old-url/kapouetttt/something");
	printSearchedResult(*config->serverList.at(0)->root.at(0), "/1/old-url/kapouetttt/kapouet/something");
	printSearchedResult(*config->serverList.at(1)->root.at(0), "/2/2/something");
	printSearchedResult(*config->serverList.at(1)->root.at(0), "/2/hello/something");
	printSearchedResult(*config->root.at(0), "src");
	printSearchedResult(*config->serverList.at(0)->root.at(1), "/1/");
	printSearchedResult(*config->serverList.at(1)->root.at(1), "/hello/");
	printSearchedResult(*config->root.at(1), "/50x.html/");

	WebServer::DeleteInstance();
	// LocationBlock *rootData = new LocationBlock;
	// rootData->uri = "/";
	// MultiTreeNode *temp = new MultiTreeNode(rootData);
	// MultiTree root(*temp);

	// 경로 앞뒤의 '/'처리 결정해야 함
	// addChildURI(root.GetRoot(), "home");
	// addChildURI(root.GetRoot(), "etc");
	// addChildURI(root.GetRoot(), "/");
	// addChildURI(root.searchNodeOrNull("/home/"), "src/");
	// addChildURI(root.searchNodeOrNull("/home/"), "usr/");
	// addChildURI(root.searchNodeOrNull("/home/src/"), "http/");
	// addChildURI(root.searchNodeOrNull("/home/src/http/"), "html/");
	// addChildURI(root.searchNodeOrNull("/home/src/http/"), "css/");
	// addChildURI(root.searchNodeOrNull("/home/src/"), "http/html");
	// addChildURI(root.searchNodeOrNull("/home/src/"), "ftp/");
	// addChildURI(root.searchNodeOrNull("/home/src/"), "image");
	// addChildURI(root.searchNodeOrNull("/home/src/image/"), "png/");
	// addChildURI(root.searchNodeOrNull("/home/src/image/"), "jpg/");

	// // std::cout << Colors::BoldWhiteString("\n[Let's get it on]") << std::endl;
	// printSearchedResult(root, "/home/src/http/html/index.html");
	// printSearchedResult(root, "/home/src/http/http.conf");
	// printSearchedResult(root, "/home/src/http/css/sstyle.cs");
	// printSearchedResult(root, "/etc/something");
	// printSearchedResult(root, "\'nothing\'");
	// printSearchedResult(root, "/something");
}
