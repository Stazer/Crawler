#include <Crawler/Worker.hpp>
#include <Crawler/Website.hpp>
#include <Crawler/WorkerManager.hpp>


Crawler::Worker::Worker ( Crawler::WorkerManager & workerManager ) :
	workerManager ( workerManager ) ,
	thread ( & Crawler::Worker::main , this )
{
}

Crawler::WorkerManager & Crawler::Worker::getWorkerManager ( )
{
	return this->workerManager ;
}

const Crawler::WorkerManager & Crawler::Worker::getWorkerManager ( ) const
{
	return this->workerManager ;
}

bool Crawler::Worker::hasWebsite ( ) const
{
	return this->website ;
}

Crawler::Website & Crawler::Worker::getWebsite ( )
{
	return * this->website;
}
	

const Crawler::Website & Crawler::Worker::getWebsite ( ) const
{	
	return * this->website ;
}

bool Crawler::Worker::isRunning ( ) const
{
	return this->running ;
}

void Crawler::Worker::setRunning ( bool running )
{
	this->running = running ;
}

void Crawler::Worker::launch ( )
{
}

void Crawler::Worker::terminate ( )
{
	this->setRunning ( false ) ;
	this->wait ( ) ;
}

void Crawler::Worker::wait ( )
{
	this->thread.wait ( ) ;
}

void Crawler::Worker::kill ( )
{
	this->thread.terminate ( ) ;
}


/*
void Crawler::Worker::parse_anchor_tag(char *anchor, std::vector<string> &results){

		char *href = std::strstr(anchor, "href=\""); 
		if(href == NULL)
			return; 
		
		char *link = href + 6; 
		
		char *end = std::strstr(link, "\""); 
		if(end == NULL)
			return; 
		
		*end = '\0'; 
		
		std::string result = link; 
		results.push_back(result); 
}



void Crawler::Worker::main ( )
{
	this->launch();
    http.setHost(//fetch link);
    resquest(website->toString);//would this be the right method to use?
    response = http.sendRequest(resquest);
    status = response.getStatus();
    if(status == sf::Http::Response::Ok){
        document = response.getBody();
    }
    else
    {
        std::cout<<"Error" << status << std::endl;
    }
    
    ifstream f(document); 
	
	f.seekg(0, ios::end);
	auto size = f.tellg();
	f.seekg(0, ios::beg);
	
	vector<char> document(size);
	
	f.read(document.data(), size);
	f.close(); 
		
    char* page_position = document.data(); 
    while(1){
    
    	page_position = strstr(page_position,"<a");
    	if(page_position == NULL){
    		break;
    	}
    	char *anchor; 
		anchor = page_position; 
    	page_position = strstr(page_position, ">");
    	*page_position = '\0';
    	page_position++;   
    }
    		
}
			*/
