#include "Game.h"


EntityManager manager;
auto& objectSq(manager.addEntity("square"));
using namespace std;
Game::Game()
{


}

Game::~Game()
{

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_BORDERLESS;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		m_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 255);
		}

		isRunning = true;
	}
	m_mapObjVectorArray.push_back(m_factory->initEntitySq(objectSq, Vector2(200, 200), Vector2(60, 60), m_textureArray[0], false, *m_renderer));
	
	
}

void Game::handleEvents()
{
	
	SDL_PollEvent(&m_event);
	std::string path = "ART/tst.jpg";
	//auto t_objectSq = objectSq;
	switch (m_event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_KEYDOWN:
		switch (m_event.key.keysym.sym)
		{
		case SDLK_UP:
			m_mapObjVectorArray.push_back(m_factory->initEntitySq(objectSq, Vector2(200, 200), Vector2(60, 60), m_textureArray[textArrIndex], false, *m_renderer));
			break;

		case SDLK_DOWN:
			
			Capture(path);
			break;

		case SDLK_LEFT:
			textArrIndex--;
			if (textArrIndex < 0)
			{
				textArrIndex = 2;
			}
			break;

		case SDLK_RIGHT:
			textArrIndex++;
			if (textArrIndex > 2)
			{
				textArrIndex = 0;
			}
			break;

		default:
			
			break;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		m_mouseDown = true;
		
		break;
	case SDL_MOUSEBUTTONUP:
		m_mouseDown = false;
	default:
		if(m_mouseDown)
		{
			manager.handleEvents(m_event.button);
		}
		
		break;
	}

}

void Game::update()
{
	
	manager.update();

}

void Game::subSystemUpdate()
{
	
}

void Game::render()
{
	SDL_RenderClear(m_renderer);
	manager.draw(m_renderer);

	SDL_RenderPresent(m_renderer);
}


void Game::clean()
{
	
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	isRunning = false;
}




void Game::initEnts(Entity &t_ent,Vector2 t_pos,Vector2 t_size, std::string t_str, bool t_isAnim)
{
	

}

void Game::updateEnts(Entity& t_ent, Vector2 t_pos, Vector2 t_size, std::string t_str, bool t_isAnim)
{

}

void Game::Capture(std::string &t_path)
{
	//setting to the screen shot
	keybd_event(VK_SNAPSHOT, 0x45, KEYEVENTF_EXTENDEDKEY, 0);
	keybd_event(VK_SNAPSHOT, 0x45, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);

	Sleep(1000);
	//handler of the bitmap that save the screen shot
	HBITMAP hBitmap;

	//take the screen shot
	OpenClipboard(NULL);

	//save the screen shot in the bitmap handler
	hBitmap = (HBITMAP)GetClipboardData(CF_BITMAP);

	//relese the screen shot
	CloseClipboard();

	std::vector<BYTE> buffer;
	IStream* stream = NULL;
	HRESULT hr = CreateStreamOnHGlobal(0, TRUE, &stream);
	CImage image;
	ULARGE_INTEGER liSize;

	// screenshot to jpg and save to stream
	image.Attach(hBitmap);
	image.Save(stream, Gdiplus::ImageFormatJPEG);
	IStream_Size(stream, &liSize);
	DWORD length = liSize.LowPart;
	IStream_Reset(stream);
	buffer.resize(length);
	IStream_Read(stream, &buffer[0], length);
	stream->Release();

	// put the imapge in the file
	std::fstream file;
	file.open(t_path, std::fstream::binary | std::fstream::out);
	file.write(reinterpret_cast<const char*>(&buffer[0]), buffer.size() * sizeof(BYTE));
	file.close();
}


