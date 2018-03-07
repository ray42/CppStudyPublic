/*
 * =========================================================================
 * Copyright (c) 2017, Raymon White - All Rights Reserved
 * Author:  Raymon White (ray), rayaxiom42 AT gmail DOT com
 * =========================================================================
 */
#include<iostream>
using std::cout; using std::endl;

#include<string>
using std::string;

#include<memory>
using std::shared_ptr;
using std::unique_ptr;

#include<vector>
using std::vector;

//Exercise 12.14: Write your own version of a function that uses a
//shared_ptr to manage a connection.

// represents what we are connecting to
struct destination
{
  string ip;
  int port;
  destination(const std::string& i="",const int p=0):
    ip(i),port(p)
  {}
};

// information needed to use the connection
struct connection
{
  string ip;
  int port;
  vector<int>* iv_pt=0;

  connection(const string& i="",const int p=0):
    ip(i),port(p)
  {
    // This needs to be freed properly.
    iv_pt = new vector<int>({1,2,3});
  }
};

// open the connection
auto connect(destination* dest_pt)->connection
{
  cout << "Creating connection, ip: " << dest_pt->ip
       << ", port: " << dest_pt->port << endl;
  return connection(dest_pt->ip,dest_pt->port);
}

void disconnect(connection& conn)
{
  cout << "disconnecting " << conn.ip << ", on port " << conn.port << endl;
  delete conn.iv_pt; conn.iv_pt=0;
  conn.ip="";
  conn.port=0;
}

void print_connection(const connection& conn)
{
  cout << "print_connection: ip: " << conn.ip 
       << ", port: " << conn.port << ", ";
  if(conn.iv_pt)
  {
    cout << "iv_pt: ";
    for(const auto& i : *(conn.iv_pt))
      cout << i << " ";
    cout << endl;
  }
  else
  {
    cout << "iv_pt is null" << endl;
  }
}

void end_connection(connection* conn)
{
  disconnect(*conn);
}

int main()
{
  cout << endl;
  
  {
    // Create a destination to create a connection.
    destination dst("RayPC",42);
    connection cnn = connect(&dst);

    // Remember that we must disconnect the connection:
    print_connection(cnn);
    disconnect(cnn);
    print_connection(cnn);
  }

  cout << endl;
  // However, we can use shared_ptr to do it for us in case we forget:
  // create a new dest and connection
  destination dst("JoJoPC", 43);
  connection cnn = connect(&dst);
  print_connection(cnn);
  {
    shared_ptr<connection> cnn_spt(&cnn,end_connection);
    // Now it should automatically disconnect
  }
  print_connection(cnn);

//Exercise 12.15: Rewrite the first exercise to use a lambda in place of the
//end_connection function.
  cout << "\nNow doing with lambda" << endl;
  destination dst2("AnotherPC", 44);
  connection cnn2 = connect(&dst2);
  print_connection(cnn2);
  {
    shared_ptr<connection> cnn2_spt(&cnn2,
        [](connection *p)
        {
          disconnect(*p);
        });
  }
  print_connection(cnn2);

  cout << "\n\nNow testing uniqueptr" << endl;

  // testing unique_ptr
  destination d3 =destination("uniquetest",45);
  connection c3 = connect(&d3);
  print_connection(c3);
  {
    // this does not work
//    unique_ptr<connection, decltype(end_connection)>
//      p(&c3,end_connection);
    
    // this works
    unique_ptr<connection, decltype(end_connection)*>
      p(&c3,end_connection);
  }
  return 0;
}
