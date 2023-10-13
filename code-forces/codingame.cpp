#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <utility>

using namespace std;
#define all(v) v.begin(), v.end()
#define rall(v) v.rbgin(), v.rend()

struct Cell {
	int scrap_amount;
	int owner;
	int units;
	bool recycler;
	bool can_build;
	bool can_spawn;
	bool in_range_of_recycler;
    int x;
    int y;
    bool in_fight;

    Cell(void):x(-1), y(-1),in_fight(false){}

    Cell(int _x, int _y):x(_x), y(_y), in_fight(false) {}

    Cell(Cell const& cell) { *this = cell;}

    Cell& operator=(Cell const& cell) {
        this->scrap_amount = cell.scrap_amount;
        this->owner = cell.owner;
        this->units = cell.units;
        this->recycler = cell.recycler;
        this->can_build = cell.can_build;
        this->can_spawn = cell.can_build;
        this->in_range_of_recycler = cell.in_range_of_recycler;
        this->x = cell.x;
        this->y = cell.y;
        this->in_fight = cell.in_fight;
        return *this;
    }
    bool operator==(Cell const& cell) { return this->x == cell.x && this->y == cell.y; }
};

struct Robot {
    int x;
    int y;
    bool in_fight;
    Robot(void):x(-1), y(-1){}
    Robot(int _x, int _y): x(_x), y(_y), in_fight(false) {}
    Robot(Robot const& robot) { *this = robot; }
    Robot& operator=(Robot const& robot) {
        this->x = robot.x;
        this->y = robot.y;
        this->in_fight = robot.in_fight;
        return *this;
    }
    bool operator==(Robot const& robot) { return this->x == robot.x && this->y == robot.y; }
};

typedef vector<Cell> vc;
typedef vector<vc> vvc;
typedef vector<Robot> vr;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<vb> vvb;

#define MAX_SIZE 289
int width;
int height;
int my_matter;
int opp_matter;
short is_left{-1};
short is_up{-1};
int curr_round;
vc voronoi_cells;
int cell_reserved[MAX_SIZE];
int spawn_times{1};
multimap<string, vpii> units_paths;
bool we_are_in_fight;
string where_to_spawn;
Cell most_up_vor_cell;
Cell most_down_vor_cell;
bool collect;

namespace math_tools {
    int bexp(int x, int n)
    {
        int  res = 1;
        while (n)
        {
            if (n&1)
                res = (res * x);
            x = (x * x);
            n >>= 1;
        }
        return res; 
    }

    float distance(int x1, int y1, int x2, int y2) {
        return sqrt(bexp((x1 - x2), 2) + bexp((y1 - y2), 2));
    }
}
namespace bfs {
    Cell normal_bfs(vvc& map, Cell cell, bool phase) {
        queue<Cell> q;
        vvb visited(height, vb(width, false));

        q.push(cell);
        visited[cell.y][cell.x] = true;
        while (!q.empty()) {
                int curr_x = q.front().x;
                int curr_y = q.front().y;
                q.pop();

                if (is_left == 1) {
                    if (curr_x + 1 < width && !visited[curr_y][curr_x + 1] && map[curr_y][curr_x + 1].scrap_amount && !map[curr_y][curr_x + 1].recycler)
                        q.push(Cell(curr_x + 1, curr_y)),
                        visited[curr_y][curr_x + 1] = true;
                    if (phase && curr_x - 1 >= 0 && !visited[curr_y][curr_x - 1] && map[curr_y][curr_x - 1].scrap_amount && !map[curr_y][curr_x - 1].recycler)
                        q.push(Cell(curr_x - 1, curr_y)),
                        visited[curr_y][curr_x - 1] = true;
                } else {
                    if (curr_x - 1 >= 0 && !visited[curr_y][curr_x - 1] && map[curr_y][curr_x - 1].scrap_amount && !map[curr_y][curr_x - 1].recycler)
                        q.push(Cell(curr_x - 1, curr_y)),
                        visited[curr_y][curr_x - 1] = true;
                    if (phase && curr_x + 1 < width && !visited[curr_y][curr_x + 1] && map[curr_y][curr_x + 1].scrap_amount && !map[curr_y][curr_x + 1].recycler)
                        q.push(Cell(curr_x + 1, curr_y)),
                        visited[curr_y][curr_x + 1] = true;
                }
                if (is_up == 1) {
                    if (curr_y + 1 < height && !visited[curr_y + 1][curr_x] && map[curr_y + 1][curr_x].scrap_amount && !map[curr_y + 1][curr_x].recycler)
                        q.push(Cell(curr_x, curr_y + 1)),
                        visited[curr_y + 1][curr_x] = true;
                    if (curr_y - 1 >= 0 && !visited[curr_y - 1][curr_x] && map[curr_y - 1][curr_x].scrap_amount && !map[curr_y - 1][curr_x].recycler)
                        q.push(Cell(curr_x, curr_y - 1)),
                        visited[curr_y - 1][curr_x] = true;
                } else {
                    if (curr_y - 1 >= 0 && !visited[curr_y - 1][curr_x] && map[curr_y - 1][curr_x].scrap_amount && !map[curr_y - 1][curr_x].recycler)
                        q.push(Cell(curr_x, curr_y - 1)),
                        visited[curr_y - 1][curr_x] = true;
                    if (curr_y + 1 < height && !visited[curr_y + 1][curr_x] && map[curr_y + 1][curr_x].scrap_amount && !map[curr_y + 1][curr_x].recycler)
                        q.push(Cell(curr_x, curr_y + 1)),
                        visited[curr_y + 1][curr_x] = true;
                }
                if (map[curr_y][curr_x].owner != 1) {
                    return Cell(curr_x, curr_y);
                }
        }
        return Cell(-1, -1);
    }
}
namespace streams {
    void print_move(int amount, Robot& robot, Cell& cell) {
        cout << "MOVE " << amount << " " << robot.x << " " << robot.y << " " << cell.x << " " << cell.y << " ;";
    }
    void print_spawn(int amount, Cell& cell) {
        cout << "SPAWN " << amount << " " << cell.x << " " << cell.y << " ;";
    }
     void print_spawn(int amount, Robot& robot) {
        cout << "SPAWN " << amount << " " << robot.x << " " << robot.y << " ;";
    }
    void print_build(Cell& cell) {
        cout << "BUILD " << cell.x << " " << cell.y << " ;";
    }
};
namespace tools {
    int 	scrap_amount_to_lose(vvc& map, int x, int y)
    {
        int dx[5][2] = {{0, 0},{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        int count = 0;

        for (int i = 0; i < 5; i++)
        {
            int nx = x + dx[i][0], ny = y + dx[i][1];
            if (nx >= 0 && nx < width && ny >= 0 && ny < height and map[ny][nx].recycler)
                count++;
        }
        return count;
    }
    void    decrement_scrap_amount(vvc &map)
    {
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                map[i][j].scrap_amount -= min(scrap_amount_to_lose(map, j, i), map[i][j].scrap_amount);
    }
    bool 	is_valid_move(vvc &map, Cell c, Cell t)
    {
        int x_start{c.x};

        while (x_start >= 0 && x_start >= t.x) {
            if (!map[c.y][x_start].scrap_amount || map[c.y][x_start].recycler)
                break;
            if (x_start == t.x)
                return true;
            --x_start;
        }
        while (x_start < width && x_start <= t.x) {
            if (!map[c.y][x_start].scrap_amount || map[c.y][x_start].recycler)
                break;
            if (x_start == t.x)
                return true;
            ++x_start;
        }
        return false;
    }
    void print_the_map(vvc& map) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (map[i][j].recycler)
                    cerr << "R";
                else if (!map[i][j].scrap_amount)
                    cerr << "G";
                else if (map[i][j].owner == 1)
                    cerr << (map[i][j].units ? "MU":"MC");
                else if (!map[i][j].owner)
                    cerr << (map[i][j].units ? "OU":"OC");
                else if (map[i][j].owner == -1)
                    cerr << "N";
                cerr << '\t';
            }
            cerr << endl;
        }
    }
    void print_voronoi_map(vvi& map) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (map[i][j] == 1)
                    cerr << "M";
                else if (map[i][j] == 0)
                    cerr << "O";
                else if (map[i][j] == -2)
                    cerr << "*";
                else if (map[i][j] == -1)
                    cerr << ".";
                else if (map[i][j] == -3)
                    cerr << "?";
                cerr << "  ";
            }
            cerr << endl;
        }
    }
    void print_robots_next_target(Robot& robot, Cell& target) {
        cerr << robot.x << " " << robot.y << "--->" << target.x << " " << target.y << endl;
    }
    void print_voronoi_next_target(Cell& cell, Robot& target) {
        cerr << cell.x << " " << cell.y << "--->" << target.x << " " << target.y << endl;
    }
}
namespace voronoi {
    vc voronoi(vvc map, vr my_robots, vr opp_robots)
    {
        vvi t_map(height, vector<int>(width));
        int dx[4][2] =  {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        queue <pair <int, int>> mine;
        queue <pair <int, int>> opp;
        vc res;

        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
                t_map[i][j] = -1 - 2 * (!map[i][j].scrap_amount or map[i][j].recycler);
        for (Robot& robot : my_robots)
            if (!map[robot.y][robot.x].recycler)
                t_map[robot.y][robot.x] = 1,
                mine.push({robot.x, robot.y});
        for (Robot& robot : opp_robots)
            if (!map[robot.y][robot.x].recycler)
                t_map[robot.y][robot.x] = 0,
                opp.push({robot.x, robot.y});
        while (!mine.empty() || !opp.empty())
        {
            queue <pair <int, int>> t_mine;
            while (!mine.empty())
            {
                int x = mine.front().first, y = mine.front().second;

                mine.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x1 = x + dx[i][0], y1 = y + dx[i][1];
                    if (x1 >= 0 and x1 < width and y1 >= 0 and y1 < height)
                    {
                        if (t_map[y1][x1] == -1)
                            t_map[y1][x1] = 1,
                            t_mine.push({x1, y1});
                        else if (t_map[y1][x1] == 0)
                            res.push_back(Cell(x1, y1)),
                            t_map[y1][x1] = -2;
                    }
                }
            }
            queue <pair <int, int>> t_opp;
            while (!opp.empty())
            {
                int x = opp.front().first, y = opp.front().second;

                opp.pop();
                for (int i = 0; i < 4; i++)
                {
                    int x1 = x + dx[i][0], y1 = y + dx[i][1];
                    if (x1 >= 0 and x1 < width and y1 >= 0 and y1 < height)
                    {
                        bool can_be_add = true;
                        for (int j = 0; j < 4; j++)
                        {
                            int x2 = x1 + dx[j][0], y2 = y1 + dx[j][1];
                            if (x2 >= 0 and x2 < width and y2 >= 0 and y2 < height)
                                if (t_map[y2][x2] == 1)
                                    can_be_add = false;
                        }
                        if (can_be_add and t_map[y1][x1] == -1)
                            t_map[y1][x1] = 0,
                            t_opp.push({x1, y1});
                        else if (t_map[y1][x1] == -1)
                            t_map[y1][x1] = 0;
                    } 
                }
            }
            tools::decrement_scrap_amount(map);
            for (int i = 0; i < height; i++)
                for (int j = 0; j < width; j++)
                    if (!map[i][j].scrap_amount)
                        t_map[i][j] = -3;
            t_mine.swap(mine);
            t_opp.swap(opp);
        }
         return res;
    }
    Robot bfs_voronoi_cell_to_robot(vvc &map, Cell& c)
    {
        queue <pair<int, int>> q;
        int visited[100][100] = {0};
        int dx[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        q.push({c.x, c.y});
        visited[c.y][c.x] = 1;
        while (!q.empty())
        {
            int t_x = q.front().first, t_y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = t_x + dx[i][0], ny = t_y + dx[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx])
                {
                    if (map[ny][nx].owner == 1 && map[ny][nx].units && !map[ny][nx].recycler && !map[ny][nx].in_fight)
                        return Robot(nx, ny);
                    else if (map[ny][nx].owner && map[ny][nx].scrap_amount) {
                        q.push({nx, ny});
                        visited[ny][nx] = 1;
                    }
                }
            }
        }
        return Robot(-1, -1);
    }
    Cell bfs_voronoi_cell_to_cell(vvc &map, Cell& c)
    {
        queue <pair<int, int>> q;
        int visited[100][100] = {0};
        int dx[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        q.push({c.x, c.y});
        visited[c.y][c.x] = 1;
        while (!q.empty())
        {
            int t_x = q.front().first, t_y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = t_x + dx[i][0], ny = t_y + dx[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx])
                {
                    if (map[ny][nx].owner == 1 && !map[ny][nx].recycler && !map[ny][nx].in_fight)
                        return Cell(nx, ny);
                    else if (map[ny][nx].owner && map[ny][nx].scrap_amount) {
                        q.push({nx, ny});
                        visited[ny][nx] = 1;
                    }
                }
            }
        }
        return Cell(-1, -1);
    }
    Cell  bfs_robot_to_voronoi_cell(vvc &map, Robot& r)
    {
        queue <pair<int, int>> q;
        vvb visited(height, vb(width, false));
        int dx[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        q.push({r.x, r.y});
        visited[r.y][r.x] = true;
        while (!q.empty())
        {
            int cur_x = q.front().first, cur_y = q.front().second;

            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = cur_x + dx[i][0], ny = cur_y + dx[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx])
                {
                    auto it = find(all(voronoi_cells), Cell(nx, ny));
                    if (it != voronoi_cells.end())
                        return Cell(nx, ny);
                    if (map[ny][nx].scrap_amount && !map[ny][nx].recycler)
                    {
                        q.push({nx, ny});
                        visited[ny][nx] = true;
                    }
                }
            }
        }
        return Cell(-1, -1);
    }
    vpii construct_the_path(pii parent[],Cell& src,  Robot& dst) {
        vpii path;
        int x = dst.x, y = dst.y;
        while (1) {
            if (parent[y * width + x].first == src.x && parent[y * width + x].second == src.y)
                break;
            path.push_back({x, y});
            int t_x = x;
            x = parent[y * width + x].first;
            y = parent[y * width + t_x].second;
         }
        path.push_back({x, y});
        path.push_back({src.x, src.y});
        path.erase(path.begin());
        return path;
    }
    
    vpii a_star_sides(vvc& map, Cell& src, Robot& dst) 
    {
        int visited[100][100] = {0};
        pii parent[286] ={{-1, -1}};
        int dx[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;

        q.push({src.x, src.y});
        visited[src.y][src.x] = 1;
        while (!q.empty())
        {
            int t_x = q.front().first, t_y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = t_x + dx[i][0], ny = t_y + dx[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx])
                {
                    if (nx == dst.x && ny == dst.y){
                        parent[ny * width + nx] = {t_x, t_y};
                        return construct_the_path(parent, src,  dst);
                    }
                    else if (map[ny][nx].owner && map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                        parent[ny * width + nx] = {t_x, t_y};
                        q.push({nx, ny});
                        visited[ny][nx] = 1;
                     }
                }
            }
        }
        return {};
    }
    vpii a_star(vvc& map, Cell& src, Robot& dst) 
    {
        int visited[100][100] = {0};
        pii parent[286] ={{-1, -1}};
        int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;

        q.push({src.x, src.y});
        visited[src.y][src.x] = 1;
        while (!q.empty())
        {
            int t_x = q.front().first, t_y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nx = t_x + dx[i][0], ny = t_y + dx[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx])
                {
                    if (nx == dst.x && ny == dst.y){
                        parent[ny * width + nx] = {t_x, t_y};
                        return construct_the_path(parent, src,  dst);
                    }
                    else if (map[ny][nx].owner && map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                        parent[ny * width + nx] = {t_x, t_y};
                        q.push({nx, ny});
                        visited[ny][nx] = 1;
                     }
                }
            }
        }
        return {};
    }

    void    send_robots_to_edge_cells(vvc& map) {
        if (my_matter < 10) return;
        if (!cell_reserved[most_up_vor_cell.y * width + most_up_vor_cell.x])
        {
            Robot r;
            for (int y = 0; y < height; y++) {
                bool found{false};

                for (int x = 0; x < width; x++)
                    if (map[y][x].owner == 1 && map[y][x].units && !map[y][x].recycler) {
                        r = Robot(x, y);
                        found = true;
                        break;
                    }
                if (found) break;
            }
            streams::print_spawn(1, r); 
            my_matter -= 10;
            cell_reserved[most_up_vor_cell.y * width + most_up_vor_cell.x]++;
            vpii path = a_star_sides(map, most_up_vor_cell, r);
            units_paths.insert({to_string(r.x) + to_string(r.y), move(path)});
        }
        if (!cell_reserved[most_down_vor_cell.y * width + most_down_vor_cell.x])
        {
            Robot r;
            for (int y = height - 1; y >= 0; --y) {
                bool found{false};

                for (int x = width - 1; x >= 0; --x)
                    if (map[y][x].owner == 1 && map[y][x].units && !map[y][x].recycler) {
                        r = Robot(x, y);
                        found = true;
                        break;
                    }
                if (found) break;
            }
            map[r.y][r.x].units--;
            cell_reserved[most_down_vor_cell.y * width + most_down_vor_cell.x]++;
            vpii path = a_star_sides(map, most_down_vor_cell, r);
            units_paths.insert({to_string(r.x) + to_string(r.y), move(path)});
        }
    }
    int     count_enemy(vvc& map, int x_start, int y_start, int dx[][2]) {
        int cnt{0};
        queue<pii> q;
        vvb visited(height, vb(width, false));

        q.push({x_start, y_start});
        visited[y_start][x_start] = true;
        while (!q.empty())
        {
            int cur_x = q.front().first, cur_y = q.front().second;

            q.pop();
            for (int i = 0; i < 4; ++i) {
                if (!dx[i][0] && !dx[i][1]) continue;
                int nx = cur_x + dx[i][0], ny = cur_y + dx[i][1];
                if (nx >= 0 && nx < width && ny >= 0 && ny < height && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    if (!map[ny][nx].owner) cnt += map[ny][nx].units;
                    if (map[ny][nx].owner != 1 && map[ny][nx].scrap_amount && !map[ny][nx].recycler) q.push({nx, ny});
                }
            }
        }
        return cnt;
    }
    void    spawn_by_priority(vvc& map, vr& my_robots, vr& opp_robots) {
        multimap<int, pii> priority;

        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (map[i][j].owner == 1 && !map[i][j].recycler && map[i][j].scrap_amount && !map[i][j].in_fight) {
                    int dx[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
                    int dxx[4][2] = {{1, 0}, {-1, 0}, {0,-1}, {0, 1}};

                    for (int k = 0; k < 4; ++k) {
                        int nx = j + dxx[k][0], ny = i + dxx[k][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height || map[ny][nx].owner == 1
                            || !map[ny][nx].scrap_amount || map[ny][nx].recycler)
                            continue;
                        dx[k][0] = dxx[k][0];
                        dx[k][1] = dxx[k][1];
                    }
                    int cnt = count_enemy(map, j, i, dx);
                     if (cnt)
                        priority.insert({cnt, {j, i}});
                }
            }
        }
        while (my_matter >= 10) {
             int matter_before = my_matter;
            for (multimap<int, pii>::reverse_iterator rit = priority.rbegin(); rit != priority.rend(); ++rit) {
                if (my_matter < 10) break;
                int x = rit->second.first, y = rit->second.second;
                Robot r(x, y);

                streams::print_spawn(1, r);
                my_matter -= 10;
                Cell c = bfs_robot_to_voronoi_cell(map, r);
                if (c.x == -1) continue;
                vpii path = a_star(map, c, r);
                units_paths.insert({to_string(r.x) + to_string(r.y), move(path)});
            }
            if (matter_before == my_matter) break;
        }
    }
    void    new_explore(vvc map, vr &my_robots, vr& opp_robots) {
        vvc t_map = map;
        int units_amount = my_robots.size();

        if (curr_round >= 2)
            send_robots_to_edge_cells(map);
        for (int i = 0; i < 289; ++i)
            if (cell_reserved[i])
                units_amount -= cell_reserved[i];
        int cur_spawn_times = cell_reserved[voronoi_cells[0].y * width + voronoi_cells[0].x];
        bool found{false};
        for (int i = 1; i < voronoi_cells.size(); ++i) {
            if (cell_reserved[voronoi_cells[i].y * width + voronoi_cells[i].x] != cur_spawn_times) {
                found = true;
                break;
            }
        }
        if (!found && !we_are_in_fight) ++spawn_times;
        while (units_amount > 0) {
            for (Cell& c : voronoi_cells)
            {
                if (units_amount == 0)
                    break;
                if (cell_reserved[c.y * width + c.x] == spawn_times) {
                    units_amount -= cell_reserved[c.y * width + c.x];
                    continue;
                }
                Robot r = bfs_voronoi_cell_to_robot(map, c);
                if (r.x == -1)
                    break;
                units_amount--;
                ++cell_reserved[c.y * width + c.x];
                map[r.y][r.x].units -= !!map[r.y][r.x].units;
                vpii path = a_star(map, c, r);
                units_paths.insert({to_string(r.x) + to_string(r.y), move(path)});
            }
            if (we_are_in_fight) break;
        }
        if (my_matter >= 10)
            spawn_by_priority(map, my_robots, opp_robots);
        for (Robot& robot: my_robots) {
            if (robot.in_fight)
                continue;
            auto nh = units_paths.extract(to_string(robot.x) + to_string(robot.y));
            if (nh.empty() || nh.mapped().empty()) {
                robot.in_fight = true;
                continue;
            }
            int x = nh.mapped().begin()->first, y = nh.mapped().begin()->second;
            nh.mapped().erase(nh.mapped().begin());
            if (!nh.mapped().empty()) {
                nh.key() = to_string(x) + to_string(y);
                units_paths.insert(move(nh));
            }
            Cell target(x,y);
            streams::print_move(1, robot, target);
        }
    }
    void    explore(vvc map, vr &my_robots, vr& opp_robots)
    {
        vvc t_map = map;
        int units_amount = my_robots.size();

        send_robots_to_edge_cells(map);
        // for (int i = 0; i < 289; ++i)
        //     if (cell_reserved[i])
        //         units_amount -= cell_reserved[i];
        int cur_spawn_times = cell_reserved[voronoi_cells[0].y * width + voronoi_cells[0].x];
        bool found{false};
        for (int i = 1; i < voronoi_cells.size(); ++i) {
            if (cell_reserved[voronoi_cells[i].y * width + voronoi_cells[i].x] != cur_spawn_times) {
                found = true;
                break;
            }
        }
        if (curr_round == 1) ++units_amount;
        if (!found && !we_are_in_fight) ++spawn_times;
         while (units_amount > 0) {
            for (Cell& c : voronoi_cells)
            {
                if (units_amount <= 0)
                    break;
                if (cell_reserved[c.y * width + c.x] == spawn_times) {
                    units_amount -= cell_reserved[c.y * width + c.x];
                    continue;
                }
                Robot r = bfs_voronoi_cell_to_robot(map, c);
                if (r.x == -1)
                    break;
                units_amount--;
                ++cell_reserved[c.y * width + c.x];
                map[r.y][r.x].units -= !!map[r.y][r.x].units;
                vpii path = a_star_sides(map, c, r);
                units_paths.insert({to_string(r.x) + to_string(r.y), move(path)});
            }
            if (we_are_in_fight) break;
        }
        map = t_map;
        bool found_cell{false};
        if (!we_are_in_fight) {
            for (Cell& c : voronoi_cells) {
                if (cell_reserved[c.y * width + c.x] == spawn_times)
                    continue;
                found_cell = true;
                if (my_matter >= 10) {
                    Cell r = bfs_voronoi_cell_to_cell(map, c);
                    if (r.x == -1)
                        break;
                    streams::print_spawn(1,r);
                    ++cell_reserved[c.y * width + c.x];
                    Robot r1(r.x, r.y);
                    vpii path = a_star_sides(map, c, r1);
                    units_paths.insert({to_string(r1.x) + to_string(r1.y), move(path)});
                    my_matter -= 10;
                } else
                    break;
            }
        }
        if (!found_cell && !we_are_in_fight) {
            int spawn_up{0}, spawn_down{0};
            for (auto it = units_paths.begin(); it != units_paths.end(); ++it) {
                if (it->second.empty())
                    continue;
                if (it->second.back().first == most_up_vor_cell.x && it->second.back().second == most_up_vor_cell.y)
                    ++spawn_up;
                else if (it->second.back().first == most_down_vor_cell.x && it->second.back().second == most_down_vor_cell.y)
                    ++spawn_down;
            }
            if (spawn_up == 2 && spawn_down == 2)
                where_to_spawn = "MID";
            while (my_matter >= 10 && (where_to_spawn.empty() || where_to_spawn == "MID")) {
                Robot target;
                if (is_left == 2)
                    target = Robot(width, 0);
                for (Robot& r: my_robots) {
                    if (is_left == 1 && r.x > target.x)
                        target = r;
                    else if (r.x < target.x)
                        target = r;
                }
                streams::print_spawn(1, target);
                my_matter -= 10;
                where_to_spawn = "UP";
            }
            if (spawn_down == 2) where_to_spawn = "UP";
            else if (spawn_up == 2) where_to_spawn = "DOWN";
            while (my_matter >= 10 && (where_to_spawn == "UP" || where_to_spawn == "DOWN")) {
                Robot r;
                vpii path;
                if (where_to_spawn == "UP") {
                    r = bfs_voronoi_cell_to_robot(map, most_up_vor_cell);
                    streams::print_spawn(1, r);
                    path = a_star_sides(map, most_up_vor_cell, r);
                    where_to_spawn = "DOWN";
                } else if (where_to_spawn == "DOWN") {
                    r = bfs_voronoi_cell_to_robot(map, most_down_vor_cell);
                    streams::print_spawn(1, r);
                    vpii path = a_star_sides(map, most_down_vor_cell, r);
                    where_to_spawn = "MID";
                }
                units_paths.insert({to_string(r.x) + to_string(r.y), move(path)});
                my_matter -= 10;
            }
        }
         // move robots to their targets
        for (Robot& robot: my_robots) {
            if (robot.in_fight)
                continue;
            auto nh = units_paths.extract(to_string(robot.x) + to_string(robot.y));
            if (nh.empty() || nh.mapped().empty()) {
                robot.in_fight = true;
                continue;
            }
            int x = nh.mapped().begin()->first, y = nh.mapped().begin()->second;
            nh.mapped().erase(nh.mapped().begin());
            if (!nh.mapped().empty()) {
                nh.key() = to_string(x) + to_string(y);
                units_paths.insert(move(nh));
            }
            Cell target(x,y);
            streams::print_move(1, robot, target);
        }
    }
    int     cells_to_distroy(vvc& map, Cell& c) {
        bool up{false}, down{false}, left{false}, right{false};
        int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < 4; ++i) {
            int nx = c.x + dx[i][0], ny = c.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (map[ny][nx].scrap_amount <= map[c.y][c.x].scrap_amount)
            {
                if (i == 0)
                    right = true;
                else if (i == 1)
                    left = true;
                else if (i == 2)
                    down = true;
                else if (i == 3)
                    up = true;
            }
        }
        return (up + down + left + right);
    }
    int     cell_scrap_profit(vvc& map, Cell& c) {
        int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int profit{map[c.y][c.x].scrap_amount};

        for (int i = 0; i < 4; ++i) {
            int nx = c.x + dx[i][0], ny = c.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            profit += min(map[ny][nx].scrap_amount, map[c.y][c.x].scrap_amount);
        }
        return profit;
    }

    bool    is_articulation_point(vvc map, Cell& c) {
        int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int cells_before{0}, cells_after{0};
        Cell start;

        for (int i = 0; i < 4; ++i) {
            int nx = c.x + dx[i][0], ny = c.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (map[ny][nx].scrap_amount > map[c.y][c.x].scrap_amount) {
                start = Cell(nx, ny);
                break;
            }
        }
        if (start.x == -1) 
            return false;
        queue<pii> q;
        vector<vector<bool>> visited(height, vector<bool>(width, false));

        q.push({start.x, start.y});
        visited[start.y][start.x] = true;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;

            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i][0], ny = y + dx[i][1];
                if (nx < 0 || nx >= width || ny < 0 || ny >= height || visited[ny][nx])
                    continue;
                if (map[ny][nx].scrap_amount) {
                    ++cells_before;
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
        }
        int amount{1};
        for (int i = 0; i < 4; ++i) {
            int nx = c.x + dx[i][0], ny = c.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (map[ny][nx].scrap_amount && map[ny][nx].scrap_amount <= map[c.y][c.x].scrap_amount) {
                map[ny][nx].scrap_amount = 0;
                ++amount;
            }
        }

        map[c.y][c.x].scrap_amount = 0;
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
                visited[i][j] = false;
            
        q.push({start.x, start.y});
        visited[start.y][start.x] = true;
        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;

            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i][0], ny = y + dx[i][1];
                if (nx < 0 || nx >= width || ny < 0 || ny >= height || visited[ny][nx])
                    continue;
                if (map[ny][nx].scrap_amount) {
                    ++cells_after;
                    visited[ny][nx] = true;
                    q.push({nx, ny});
                }
            }
        }
        return ((cells_before - amount) != cells_after);
    }
    bool    is_in_range_of_recycler(vvc& map, Cell& c) {
        int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        if (map[c.y][c.x].in_range_of_recycler) return true;
        for (int i = 0; i < 4; ++i) {
            int nx = c.x + dx[i][0], ny = c.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (map[ny][nx].in_range_of_recycler)
                return true;
        }
        return false;
    }
    void    pre_build(vvc& map, vc& my_cells, vr& my_robots) {
        vc cells_to_build;

        for (Cell& c : my_cells) {
            bool found{false};
            for (auto it = units_paths.begin(); it != units_paths.end(); ++it) {
                for (auto& x:it->second) {
                    if (x.first == c.x && x.second == c.y) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) continue;
            if (map[c.y][c.x].units || (cells_to_distroy(map, c) > 2)) continue;
            if (!is_articulation_point(map, c) && cell_scrap_profit(map, c) >= 15 && !is_in_range_of_recycler(map, c)) 
                cells_to_build.push_back(c);
        }
        if (cells_to_build.empty()) return;
        sort(cells_to_build.begin(), cells_to_build.end(), [&](Cell& a, Cell& b) {
            return cell_scrap_profit(map, a) > cell_scrap_profit(map, b);
        });
        streams::print_build(cells_to_build[0]);
        my_matter -= 10;
    }
}
namespace fight {
    bool is_in_fight(vvc& map, Robot& robot) {
        int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < 4; i++) {
            int nx = robot.x + dx[i][0], ny = robot.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (map[ny][nx].owner == 0) {
                return true;
            }
        }
        return false;
    }
    void check_for_fight(vvc& map, vr& my_robots)
    {
        for (Robot& robot : my_robots) {
            if (is_in_fight(map, robot)) {
                we_are_in_fight = true;
                robot.in_fight = true;
                map[robot.y][robot.x].in_fight = true;
                units_paths.erase(to_string(robot.x) + to_string(robot.y));
            }
        }
    }
    void free_to_move(vvc& map, vr& free_robots)
    {
        if (free_robots.empty()) return; 

        set<pii> free;
        for (Robot& r : free_robots) {
            int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            bool there_is_enemy_cell{false};

            for (int i = 0; i < 4; ++i) {
                int nx = r.x + dx[i][0], ny = r.y + dx[i][1];
                if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                    continue;
                if (map[ny][nx].owner == 0 && !map[ny][nx].recycler) {
                    there_is_enemy_cell = true;
                    break;
                }
            }
            if (there_is_enemy_cell)
                free.insert({r.x, r.y});
        }
        if (free.size() > (opp_matter / 10) || collect) {
            for (Robot& r:free_robots) {
                Cell c = bfs::normal_bfs(map, Cell(r.x, r.y), 0); 
                if (c.x == -1)
                    c = bfs::normal_bfs(map, Cell(r.x, r.y), 1);
                if (c.x != -1) {
                    streams::print_move(1, r, c);
                    map[r.y][r.x].units--;
                }
            }
        } else {
            for (Robot& r:free_robots) {
                int dxd[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                int dxu[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
                int dxx[2][2] = {{0, 1}, {0, -1}};  
                Cell target;
                int enemy_units_up{0}, enemy_units_down{0};
                bool there_is_up{false}, there_is_down{false};

                for (int i = 0; i < 2; ++i) {
                    int nx = r.x + dxx[i][0], ny = r.y + dxx[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                        continue;
                    if (map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                        if (i == 0) there_is_down = true;
                        else there_is_up = true;
                    }
                }
                if (there_is_down || there_is_up) {
                    for (int i = 0; i <= r.y; ++i)
                        for (int j = 0; j < width; ++j)
                            if (map[i][j].owner == 0 && map[i][j].units)
                                enemy_units_up += map[i][j].units;

                    for (int i = r.y; i < height; ++i)
                        for (int j = 0; j < width; ++j)
                            if (map[i][j].owner == 0 && map[i][j].units)
                                enemy_units_down += map[i][j].units;

                    for (int i = 0; i < 4; ++i) {
                        int nx, ny;
                        if (enemy_units_up > enemy_units_down) nx = r.x + dxu[i][0], ny = r.y + dxu[i][1];
                        else nx = r.x + dxd[i][0], ny = r.y + dxd[i][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                            continue;
                        if (map[ny][nx].owner && map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                            target = Cell(nx, ny);
                            break;
                        }
                    }
                } else {
                    int dx[2][2] = {{1, 0}, {-1, 0}};
                    for (int i = 0; i < 2; ++i) {
                        int nx = r.x + dx[i][0], ny = r.y + dx[i][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                            continue;
                        if (!map[ny][nx].owner && map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                            target = Cell(nx, ny);
                            break;
                        }
                    }
                }
                streams::print_move(1, r, target);
                map[r.y][r.x].units--;
            } 
        }
    }
    void stay_and_spawn(vvc& map, Robot& r, int diff) {
        int sides{0};
        int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < 4; ++i) {
            int nx = r.x + dx[i][0], ny = r.y + dx[i][1];
            if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                continue;
            if (map[ny][nx].scrap_amount)
                sides++;
        }
        if (sides == 1) return;
        diff = abs(diff);
        if (!diff) return;
        int amount = my_matter / 10;
        amount = min(amount, diff);
        if (amount && map[r.y][r.x].scrap_amount) {
            streams::print_spawn(amount, r);
            my_matter -= amount * 10;
            map[r.y][r.x].units += amount;
        }
    }
    bool emergency_move(vvc& map, Robot& r, Cell target) {
        if (!map[r.y][r.x].scrap_amount) {
            if (map[target.y][target.x].scrap_amount)
                streams::print_move(map[r.y][r.x].units, r, target);
            else {
                int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                Cell t;
                for (int i = 0; i < 4; ++i) {
                    int nx = r.x + dx[i][0], ny = r.y + dx[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                        continue;
                    if (map[ny][nx].scrap_amount) {
                        t = Cell(nx, ny);
                        break;
                    }
                }
                streams::print_move(map[r.y][r.x].units, r, t);
            }
            map[r.y][r.x].units = 0;
            return true;
        }
        return false;
    }
    void fight(vvc& map, vr& my_robots)
    {
        int dx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int dxl[4][2] = {{0, 1}, {0, -1}, {1, 0}, {0, 0}};
        int dxr[4][2] = {{0, 1}, {0, -1}, {0, 0}, {-1, 0}};
        vr free_robots;
        set<pii> used;
        for (Robot& r : my_robots) {
            if (!r.in_fight || !map[r.y][r.x].units)
                continue;
            if (used.count({r.x, r.y}))
                continue;
            int en_left{0}, en_right{0}, en_up{0}, en_down{0};
            Cell c;
            if (collect) {
                for (int i = 0; i < 4; ++i) {
                    int nx = r.x + dx[i][0], ny = r.y + dx[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                        continue;
                    if (c.x == -1 && map[ny][nx].owner == -1 && map[ny][nx].scrap_amount)
                        c = Cell(nx, ny);
                    if (map[ny][nx].owner == 0 && map[ny][nx].units) {
                        if (i == 0)
                            en_down = map[ny][nx].units;
                        else if (i == 1)
                            en_up = map[ny][nx].units;
                        else if (i == 2)
                            en_right = map[ny][nx].units;
                        else if (i == 3)
                            en_left = map[ny][nx].units;
                    }
                }
            } else {
                for (int i = 0; i < 4; ++i) {
                    int nx, ny;
                    nx = r.x + dx[i][0], ny = r.y + dx[i][1];
                    if (is_left == 1)
                        nx = r.x + dxl[i][0], ny = r.y + dxl[i][1];
                    else
                        nx = r.x + dxr[i][0], ny = r.y + dxr[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height || (nx == r.x && ny == r.y))
                        continue;
                    if (c.x == -1 && map[ny][nx].owner == -1 && map[ny][nx].scrap_amount)
                        c = Cell(nx, ny);
                    if (map[ny][nx].owner == 0 && map[ny][nx].units) {
                        if (i == 0)
                            en_down = map[ny][nx].units;
                        else if (i == 1)
                            en_up = map[ny][nx].units;
                        else if (i == 2)
                            en_right = map[ny][nx].units;
                        else if (i == 3)
                            en_left = map[ny][nx].units;
                    }
                }
                if (c.x == -1) {
                    for (int i = 0; i < 4; ++i) {
                        int nx = r.x + dx[i][0], ny = r.y + dx[i][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                            continue;
                        if (c.x == -1 && map[ny][nx].owner == -1 && map[ny][nx].scrap_amount)
                            c = Cell(nx, ny);
                    }
                }
            }
            if (c.x != -1) {
                bool there_is_enemy{false};

                for (int i = 0; i < 4; ++i) {
                    int nx = c.x + dx[i][0], ny = c.y + dx[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                        continue;
                    if (map[ny][nx].owner == 0 && map[ny][nx].units) {
                        there_is_enemy = true;
                        break;
                    }
                }
                if (my_matter >= 10 && there_is_enemy && !map[r.y][r.x].scrap_amount) {
                    streams::print_spawn(1, r);
                    my_matter -= 10;
                    map[r.y][r.x].units++;
                }
                if (my_matter < 10 && there_is_enemy)
                    continue;
                streams::print_move(1, r, c);
                map[r.y][r.x].units--;
                if (!there_is_enemy) map[c.y][c.x].owner = 1;
            } else {
                if (!en_left && !en_right && !en_up && !en_down)
                    free_robots.push_back(r);
                if (en_right) {
                    if (emergency_move(map, r, Cell(r.x + 1, r.y)))
                        continue;
                    int diff = map[r.y][r.x].units - en_right;
                    if (diff > 0) {
                        Cell t(r.x + 1, r.y);
                        if (map[t.y][t.x].scrap_amount) {
                            streams::print_move(diff, r, t);
                            map[r.y][r.x].units -= diff;
                            used.insert({r.x, r.y});
                        }
                    }
                    else if (my_matter > 10) 
                        stay_and_spawn(map, r, diff);
                }
                if (en_left) {
                    if (emergency_move(map, r, Cell(r.x - 1, r.y)))
                        continue;
                    int diff = map[r.y][r.x].units - en_left;
                    if (diff > 0) {
                        Cell t(r.x - 1, r.y);
                        if (map[t.y][t.x].scrap_amount) {
                            streams::print_move(diff, r, t);
                            map[r.y][r.x].units -= diff;
                            used.insert({r.x, r.y});
                        }
                    }
                    else if (my_matter > 10)
                        stay_and_spawn(map, r, diff);
                } 
                if (en_up || en_down) {
                    int dr[2][2] = {{0, 1}, {0, -1}};
                    int dl[2][2] = {{0, -1}, {0, 1}};
                    Cell t;

                    for (int i = 0; i < 2; ++i) {
                        int nx, ny;
                        if (is_left == 1)
                            nx = r.x + dr[i][0], ny = r.y + dr[i][1];
                        else
                            nx = r.x + dl[i][0], ny = r.y + dl[i][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height)
                            continue;
                        if (map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                            t = Cell(nx, ny);
                            break;
                        }
                    }
                    if (t.x != -1) {
                        streams::print_move(1, r, t);
                        map[r.y][r.x].units--;
                    } else {
                        if (en_up && en_down) {
                            int diff = map[r.y][r.x].units - min(en_up, en_down);
                            if (diff > 0) {
                                Cell tn;
                                tn = (min(en_up, en_down) == en_up) ? Cell(r.x, r.y - 1): Cell(r.x, r.y + 1);
                                if (map[tn.y][tn.x].scrap_amount) {
                                    streams::print_move(diff, r, tn);
                                    map[r.y][r.x].units -= diff;
                                    used.insert({r.x, r.y});
                                }
                            } else
                                stay_and_spawn(map, r, diff);
                        } else if (en_up) {
                            int diff = map[r.y][r.x].units - en_up;
                            if (diff > 0) {
                                Cell tn(r.x, r.y - 1);
                                if (map[tn.y][tn.x].scrap_amount) {
                                    streams::print_move(diff, r, tn);
                                    map[r.y][r.x].units -= diff;
                                    used.insert({r.x, r.y});
                                }
                            } else
                                stay_and_spawn(map, r, diff);
                        } else {
                            int diff = map[r.y][r.x].units - en_down;
                            if (diff > 0) {
                                Cell tn(r.x, r.y + 1);
                                if (map[tn.y][tn.x].scrap_amount) {
                                    streams::print_move(diff, r, tn);
                                    map[r.y][r.x].units -= diff;
                                    used.insert({r.x, r.y});
                                }
                            } else
                                stay_and_spawn(map, r, diff);
                        }
                    }
                }
            }
        }
        free_to_move(map, free_robots);
    }
    void build(vvc& map, vr opp_robots) {
		multimap<int, Robot> robots_count;
		set<string> checked;
		int dxr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		int dxl[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

		for (Robot& r:opp_robots) {
			if (checked.count(to_string(r.x) + to_string(r.y))) continue;
			checked.insert(to_string(r.x) + to_string(r.y));
			robots_count.insert({map[r.y][r.x].units, r});
		}
        while (my_matter >= 10) {
            bool found{false};

            for (auto it = robots_count.rbegin(); it != robots_count.rend(); ++it) {
                Cell c;
                int my_cells_left{0}, my_cells_right{0};
                for (int i = 0 ; i <= it->second.x; ++i)
                    if (map[it->second.y][i].owner == 1) ++my_cells_left;
                for (int i = it->second.x + 1; i < width; ++i)
                    if (map[it->second.y][i].owner == 1) ++my_cells_right;

                for (int i = 0; i < 4; ++i) {
                    int nx,ny;
                    if (my_cells_left > my_cells_right)
                        nx = it->second.x + dxl[i][0], ny = it->second.y + dxl[i][1];
                    else
                        nx = it->second.x + dxr[i][0], ny = it->second.y + dxr[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
                    if (map[ny][nx].owner == 1 && !map[ny][nx].units && !map[ny][nx].recycler) {
                        c = Cell(nx, ny);
                        break;
                    }
                }
                if (c.x != -1) {
                    found = true;
                    if ((my_matter / 10) >= (it->first + (opp_matter / 10)) && map[c.y][c.x].scrap_amount) {
                        streams::print_spawn(1, c);
                        my_matter -= 10;
                        map[c.y][c.x].units++;
                    }
                    else {
                        streams::print_build(c);
                        my_matter -= 10;
                        map[c.y][c.x].recycler = true;
                    }
                }
            }
            if (!found) break;
        }
    }

    void spawn_if_we_still_have_matter(vvc& map, vc& my_cells) {
        if (curr_round >= (2 * width)) {
            collect = true;
            vc res;
            int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

            for (Cell& cell:my_cells) {
              for (int i = 0; i < 4; ++i) {
                int nx = cell.x + dx[i][0], ny = cell.y + dx[i][1];
                if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
                if (map[ny][nx].owner == -1 && map[ny][nx].scrap_amount && !map[ny][nx].recycler) {
                    res.push_back(cell);
                    break;
                }
              }
            }
            if (!res.empty()) {
                while (my_matter >= 10) {
                    int index = random() % res.size();
                    if (map[res[index].y][res[index].x].scrap_amount) {
                        streams::print_spawn(1, res[index]);
                        my_matter -= 10;
                    }
                }
            } else {
                while (my_matter >= 10) {
                    int index = random() % my_cells.size();
                    if (map[my_cells[index].y][my_cells[index].x].scrap_amount) {
                        streams::print_spawn(1, my_cells[index]);
                        my_matter -= 10;
                    }
                }
            }
       }
        if (is_left == 2) {
            sort(all(my_cells), [&](Cell& a, Cell& b) {
                return a.x < b.x;
            });
        } else {
            sort(all(my_cells), [&](Cell& a, Cell& b) {
                return a.x > b.x;
            });
        }
        while (my_matter >= 10) {
            Cell c;
            int tmp_matter = my_matter;
            for (Cell& cell:my_cells) {
                int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                int amount{0};
                int enemy_amount{0};

                for (int i = 0; i < 4; ++i) {
                    int nx = cell.x + dx[i][0], ny = cell.y + dx[i][1];
                    if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
                    if (!map[ny][nx].scrap_amount && map[ny][nx].recycler) {
                        ++amount;
                    }
                    if (map[ny][nx].owner == 0 && map[ny][nx].units)
                        enemy_amount += map[ny][nx].units;
                }
                if (amount <= 2 && map[cell.y][cell.x].units < enemy_amount) {
                    c = cell;
                    break;
                }
            }
            if (c.x == -1) {
               for (Cell& cell:my_cells) {
                    int enemy_amount{0};
                    int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

                    for (int i = 0; i < 4; ++i) {
                        int nx = cell.x + dx[i][0], ny = cell.y + dx[i][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
                        if (map[ny][nx].owner == 0 && !map[ny][nx].recycler && !map[ny][nx].units)
                            ++enemy_amount;
                    }
                    if (enemy_amount && map[cell.y][cell.x].scrap_amount) {
                        int amount = min(enemy_amount, my_matter / 10);
                        if (amount == 0) return;
                        streams::print_spawn(amount, cell);
                        my_matter -= amount * 10;
                        map[cell.y][cell.x].units += amount;
                    }
               }
               if (my_matter < 10) return;
                for (Cell& cell:my_cells) {
                    int enemy_amount{0};
                    int dx[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

                    for (int i = 0; i < 4; ++i) {
                        int nx = cell.x + dx[i][0], ny = cell.y + dx[i][1];
                        if (nx < 0 || nx >= width || ny < 0 || ny >= height) continue;
                        if (map[ny][nx].owner == 0 && !map[ny][nx].recycler)
                            ++enemy_amount;
                    }
                    if (enemy_amount && map[cell.y][cell.x].scrap_amount) {
                        int amount = min(enemy_amount, my_matter / 10);
                        if (amount == 0) return;
                        streams::print_spawn(amount, cell);
                        my_matter -= amount * 10;
                        map[cell.y][cell.x].units += amount;
                    }
               }
               if (my_matter >= 10) return;
            }
            else if (c.x != -1) {
                if (map[c.y][c.x].scrap_amount) {
                    streams::print_spawn(1, c);
                    my_matter -= 10;
                    map[c.y][c.x].units++;
                }
            }
            if (my_matter == tmp_matter) return;
        }
    }
}
int main()
{
    cin >> width >> height; cin.ignore();
    vvc map(height, vc(width));

    while (1) {
        ++curr_round;
        cin >> my_matter >> opp_matter; cin.ignore();
        vr  my_robots;
        vr  other_robots;
        vc  my_cells;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
				cin >> map[y][x].scrap_amount >> map[y][x].owner >> map[y][x].units;
				cin >> map[y][x].recycler >> map[y][x].can_build >> map[y][x].can_spawn;
				cin >> map[y][x].in_range_of_recycler;
                cin.ignore();
                if (map[y][x].owner == 1)
                    my_cells.push_back(Cell(x, y));
				if (map[y][x].units) {
                    int amount = map[y][x].units;
                    if (map[y][x].owner == 1) {
                        if (is_left == -1)
                            is_left = (x < width / 2) ? 1 : 2;
                        if (is_up == -1)
                            is_up = (y < height / 2) ? 1 : 2;
                        while (amount--)
                            my_robots.push_back(Robot(x, y));
                    } else {
                        while (amount--)
                            other_robots.push_back(Robot(x, y));
                    }
               }
            }
        }
        if (curr_round == 1) {
            voronoi_cells = voronoi::voronoi(map, my_robots, other_robots);
            most_up_vor_cell.y = height  - 1;
            most_down_vor_cell.y = 0;
            for (Cell& c : voronoi_cells) {
                if (c.y <= most_up_vor_cell.y)
                    most_up_vor_cell = c;
                if (c.y >= most_down_vor_cell.y)
                    most_down_vor_cell = c;
            }
        }
        if (curr_round != 1)
            tools::decrement_scrap_amount(map);
        fight::check_for_fight(map, my_robots);
        if (curr_round <= width / 4 && !collect)
            voronoi::pre_build(map, my_cells, my_robots);
        if (we_are_in_fight) {
            fight::build(map, other_robots);
            voronoi::explore(map, my_robots, other_robots);
            fight::fight(map, my_robots);
        }
        else
            voronoi::explore(map, my_robots, other_robots);
        if (my_matter >= 10)
            fight::spawn_if_we_still_have_matter(map, my_cells);
        cout << "WAIT;" << endl;
    }
 }