#include "main.h"

void HandleInputs(sf::Event event, sf::RenderWindow& window);

int main()
{
	sf::RenderWindow window(sf::VideoMode(m_winWidth, m_winHeight), "MazeBotDemo");
	window.setVerticalSyncEnabled(true);

	std::vector<std::function<void(sf::RenderWindow&)>> drawCall;
	std::vector<std::function<void(float dt)>> fixedUpdate;

	sf::Clock clock;

#pragma region Managers
	MazeGenerator maze(m_winWidth, m_winHeight, 25);
	GameManager* gameMan = new GameManager(maze);
	BotRenderer* botRenderer = new BotRenderer(maze);
	InputListener* inputs = new InputListener();

	drawCall.push_back([&maze](sf::RenderWindow& window) { maze.DrawMaze(window); });
	drawCall.push_back([&gameMan](sf::RenderWindow& window) { gameMan->DrawStartEnd(window); });
	drawCall.push_back([&botRenderer](sf::RenderWindow& window) { botRenderer->RenderBots(window); });

	fixedUpdate.push_back([&gameMan](float deltaTime) {gameMan->UpdateGameState(deltaTime); });
#pragma endregion

#pragma region Bots
	MazeBot depthBot("Depth Bot", sf::Color::Blue);
	MazeBot BfsBot("BFS Bot", sf::Color::Cyan);
	botRenderer->AddBot(depthBot);
	botRenderer->AddBot(BfsBot);
#pragma endregion

#pragma region Algo
	BFSPathfinder* bfsAlgo = new BFSPathfinder(BfsBot, maze);
	gameMan->AddPathfinder(bfsAlgo);

	//DepthFirstPathfinder* depthAlgo = new DepthFirstPathfinder(depthBot, maze);
	//gameMan->AddPathfinder(depthAlgo);
#pragma endregion

#pragma region UI
	BtnManager* btnMan = new BtnManager(m_winWidth);
	inputs->AddListener([&btnMan](sf::Vector2i mousePos) {btnMan->TriggerButons(mousePos); });
	drawCall.push_back([&btnMan](sf::RenderWindow& window) { btnMan->DrawBtns(window); });

	sf::Font font;
	if (!font.loadFromFile("res/Mario-Kart-DS.ttf"))
	{
		std::cerr << "No Font" << std::endl;
		return -1;
	}

	Bouton* Shuffle = new Bouton(150, 50, *new Vector2Int(0, 0), "Shuffle", font);
	Shuffle->AddListeners([&gameMan]() {gameMan->GenerateGameParameters(); });
	//Shuffle->AddListeners([&botRenderer]() {botRenderer->RefreshTrace(); });
	btnMan->AddBtn(Shuffle);

	Bouton* Start = new Bouton(150, 50, *new Vector2Int(0, 55), "Start", font);
	Start->AddListeners([&gameMan]() {gameMan->StartGame(); });
	btnMan->AddBtn(Start);
#pragma endregion

	gameMan->GenerateGameParameters();
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			HandleInputs(event, window);
			inputs->ListenForInputs(event, window);
		}

		for (auto& onFixedUpdate : fixedUpdate)
		{
			onFixedUpdate(clock.restart().asSeconds());
		}

		window.clear();

		for (auto& drawFunc : drawCall)
		{
			drawFunc(window);
		}

		window.display();
	}

	return 0;
}

void HandleInputs(sf::Event event, sf::RenderWindow& window)
{
	if (event.type == sf::Event::Closed)
		window.close();

	if (event.type == sf::Event::KeyPressed)
	{
		if (event.key.code == sf::Keyboard::Escape)
		{
			window.close();
		}
	}
}
