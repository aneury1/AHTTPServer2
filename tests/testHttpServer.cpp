// Must include the gtest header to use the testing library
#include <gtest/gtest.h>
#include "HttpServer.h"
#include <map>
/*
TEST(PathHandler, SetAndGetCorrectPath){
   HttpServer server(9000);
   server.setRootPath("/www/home");
   EXPECT_EQ(server.getRootPath(), "/www/home");
}

TEST(PathHandler, SetAndGetInvalidPath){
   HttpServer server(9000);
   server.setRootPath("/www/home");
   EXPECT_NE(server.getRootPath(), "/www/home1");
}
*/
TEST(ParseCorrectRoutes, SplitSize2){
 

  const std::string route_to_parse = "/post/<int:post_id>";
  
  auto splitWords = [](std::string word, char sp){
     std::vector<std::string> ret;
     int iter=0;
     std::string str;
     while(word[iter]!='\0'){
        
        if(word[iter]!=sp){
          str+= word[iter];
        }
        else{
            if(str.size()>0)
              ret.push_back(str);
            str="";
        }
        iter++;
     }
     if(str.size()>0)
       ret.push_back(str);
     return ret;
  };
   std::string routeToTest("/post/<int:post_id>");
   auto vec = splitWords(routeToTest, '/'); 
   EXPECT_EQ(vec.size(), 2);
}


TEST(ValidateRoutePattern, ValidateRoute){
  const std::string route_to_parse = "/post/<post_id:int>";
  const std::string uri_to_parse = "/post/1";
  std::cout <<"\n\n\n";  
  auto vecPattern = splitWords(route_to_parse, '/');
  auto vecUriToTest = splitWords(uri_to_parse, '/');
  EXPECT_EQ(vecPattern.size(), vecUriToTest.size());
  EXPECT_EQ(validatePatterByUrl(vecUriToTest, vecPattern), true);
}


TEST(ValidateRoutePattern, ValidateValidRoute){


  const std::map<std::string, ParserEndpoint> routeList={
    {"/post/<post_id:int>/ha", DefaultEndpoint},
    {"/post/<post_id:int>/hola", DefaultEndpoint},
    {"/post/<post_id:int>/", DefaultEndpointW200},
    {"/post/<post_id:int>/h", DefaultEndpoint},
    {"/post/<post_id:int>/hla", DefaultEndpoint},
 
  };
  const std::string uriRequested = "/post/1";

   auto it = getEndpointFromMap(uriRequested,routeList);
   
   EXPECT_EQ(it.first, "/post/<post_id:int>/");

   auto response = it.second(nullptr);

   EXPECT_EQ(response->statusCode, 200);
}