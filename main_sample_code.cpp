
//////////////////////////////////////C++ Library
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <fstream>
#include <random>
#include <locale>
#include <ctime>

//////////////////////////////////////CppRestSDK
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/filestream.h"
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"
#ifdef _DEBUG
#pragma comment(lib, "cpprest120d_2_9.lib")
#else
#pragma comment(lib, "cpprest120_2_9.lib")
#endif


using namespace web;                        // Common features like URIs.
using namespace http;						// Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace utility;					// Utility Tools For Program
using namespace web::json;					// Json Handler Class
using namespace utility;                    // Common utilities like string conversions
using namespace concurrency::streams;       // Asynchronous streams
using namespace std;

///////////////////////////Sample Code
///Get account info
void codeSample_getAccountInfo();

///Add person
void codeSample_addPerson();

///Edit person
void codeSample_editPerson();

///Delete person info
void codeSample_deletePerson();

///Get person info
void codeSample_getPersonInfo();

///Set person state
void codeSample_setPersonState();

///Get person state
void codeSample_getPersonState();

///Check registration
void codeSample_checkRegistration();

///Check background
void codeSample_checkBackground();

///Set Adv Security Check
void codeSample_setAdvSecurityCheck();

///Check Adv Security Check
void codeSample_getAdvSecurityCheck();

///Register Face Image
void codeSample_registerFaceImage();

///Get Face Image Info
void codeSample_getFaceInfo();

///Face Verification
void codeSample_faceVerification();

void main()
{
	///////////////////////////Sample Code
	/////Get account info
	//codeSample_getAccountInfo();

	///Add person
	//codeSample_addPerson();

	/////Edit person
	//codeSample_editPerson();

	//////Delete person info
	//codeSample_deletePerson();

	/////Get person info
	//codeSample_getPersonInfo();

	/////Set person state
	//codeSample_setPersonState();

	/////Get person state
	//codeSample_getPersonState();

	/////Check registration
	//codeSample_checkRegistration();

	/////Check background
	//codeSample_checkBackground();

	/////Set Adv Security Check
	//codeSample_setAdvSecurityCheck();

	/////Check Adv Security Check
	//codeSample_getAdvSecurityCheck();

	///Register Face Image
	codeSample_registerFaceImage();

	/////Get Face Image Info
	//codeSample_getFaceInfo();

	/////Face Verification
	//codeSample_faceVerification();
}
///////////////////////////Sample Code
///Get account info
void codeSample_getAccountInfo()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1200") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.to_string();


		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Add person
void codeSample_addPerson()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/add") };
		auto client = http_client{ U("http://localhost:1800/person/add") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.to_string();


		///Prepairing person information
		json::value inpJson;
		inpJson[L"nationalId"] = json::value::string(L"0181251256");
		inpJson[L"name"] = json::value::string(L"علی");
		inpJson[L"family"] = json::value::string(L"احمد");
		inpJson[L"address"] = json::value::string(L"تهران");
		inpJson[L"postalCode"] = json::value::string(L"1312332123");
		inpJson[L"birthdate"] = json::value::string(L"1396/10/10");
		inpJson[L"sex"] = json::value::boolean(0);
		inpJson[L"cellphone"] = json::value::string(L"0990099090");
		inpJson[L"phone"] = json::value::string(L"02144498198");


		///Sending request with data to server and waiting for answer
		client.request(methods::POST, query, inpJson).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag"<< endl;
			

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::stringstream st;
			respJson.serialize(st);
			cout << "\n" << "message version : " << st.str() << "\n";
			


		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Edit person
void codeSample_editPerson()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/add") };
		auto client = http_client{ U("http://localhost:1800/person/edit") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.to_string();


		///Prepairing person information
		json::value inpJson;
		inpJson[L"address"] = json::value::string(L"تهران");
		inpJson[L"postalCode"] = json::value::string(L"1312332123");
		inpJson[L"birthdate"] = json::value::string(L"1396/10/10");
		inpJson[L"cellphone"] = json::value::string(L"0990099090");
		inpJson[L"phone"] = json::value::string(L"02144498198");
		inpJson[L"perId"] = json::value::string(L"987029af-80f4-402b-989a-d52402a8a71e");

		///Sending request with data to server and waiting for answer
		client.request(methods::POST, query, inpJson).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::stringstream st;
			respJson.serialize(st);
			cout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Delete person info
void codeSample_deletePerson()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/delete") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "perId")
			.to_string();


		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::stringstream st;
			respJson.serialize(st);
			cout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Get person info
void codeSample_getPersonInfo()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/getInfo") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();


		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Set person state
void codeSample_setPersonState()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/setState") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.append_query(U("per-state"), "0")
			.to_string();

		///Sending request with data to server and waiting for answer
		client.request(methods::POST, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Get person state
void codeSample_getPersonState()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/checkState") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();

		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Check registration
void codeSample_checkRegistration()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/checkRegistration") };
		auto client = http_client{ U("http://localhost:1800/person/checkRegistration") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();

		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Check background
void codeSample_checkBackground()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/checkState") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();

		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Set Adv Security Check
void codeSample_setAdvSecurityCheck()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/checkState") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();

		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Check Adv Security Check
void codeSample_getAdvSecurityCheck()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/person/delete") };
		auto client = http_client{ U("http://localhost:1800/person/checkState") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();

		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Register Face Image
void codeSample_registerFaceImage()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/biometric/face/register") };
		auto client = http_client{ U("http://localhost:1800/v0.1b/biometric/face/register") };

		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();

		///reading image
		std::ifstream InFile(fileAddress, std::ifstream::binary);
		std::vector<char> data((std::istreambuf_iterator<char>(InFile)), std::istreambuf_iterator<char>());
		std::string dataStr(data.begin(), data.end());

		///Sending request with data to server and waiting for answer
		client.request(methods::POST, query, dataStr).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Get Face Image Info
void codeSample_getFaceInfo()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/biometric/face/register") };
		auto client = http_client{ U("http://localhost:1200") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("img-id"), "imgid")
			.to_string();


		///Sending request with data to server and waiting for answer
		client.request(methods::GET, query).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}

///Face Verification
void codeSample_faceVerification()
{
	try
	{

		///server address
		//auto client = http_client{ U("http://api.sahaid.ir/v0.1b/biometric/face/verification") };
		auto client = http_client{ U("http://localhost:1800/person/getInfo") };


		///building query
		auto query = uri_builder()
			.append_query(U("app-key"), "appkey")
			.append_query(U("secret-key"), "secretkey")
			.append_query(U("per-id"), "987029af-80f4-402b-989a-d52402a8a71e")
			.to_string();


		///reading image
		std::ifstream InFile(fileAddress, std::ifstream::binary);
		std::vector<char> data((std::istreambuf_iterator<char>(InFile)), std::istreambuf_iterator<char>());
		std::string dataStr(data.begin(), data.end());

		///Sending request with data to server and waiting for answer
		client.request(methods::POST, query, dataStr).then([&](http_response response)
		{
			///Checking http status code (not server response status code)
			if (response.status_code() != status_codes::OK)
				cout << "Http error flag" << endl;

			///Server response in json format
			json::value respJson = response.extract_json().get();

			///Parsing response 
			for (auto iter = respJson.as_object().cbegin(); iter != respJson.as_object().cend(); ++iter)
			{

				auto k = iter->first;
				auto v = iter->second;

				//auto key = k.as_string();
				auto value = v.to_string();

				///output on screen
				wcout << k << L" : " << value << endl;
			}

			//Convert json response to raw string and show on  screen
			std::wstringstream st;
			respJson.serialize(st);
			ucout << "\n" << "message version : " << st.str() << "\n";



		}).wait();

	}
	catch (const std::exception &e)
	{
		printf("Error exception:%s\n", e.what());
	}

	///Waiting so user can see the output
	getchar();
}