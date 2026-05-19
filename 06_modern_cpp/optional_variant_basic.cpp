#include <cstddef>
#include <iostream>
#include <optional>
#include <string>
#include <variant>
#include <vector>

struct Player {
    std::string name;
    int level;
    int hp;
};

struct DamageAction {
    std::string target_name;
    int amount;
};

struct HealAction {
    std::string target_name;
    int amount;
};

struct ChatMessage {
    std::string text;
};

struct LevelUpAction {
    std::string target_name;
    int levels;
};

using GameAction = std::variant<DamageAction, HealAction, ChatMessage, LevelUpAction>;

void print_players(const std::vector<Player>& players) {
    for (const auto& player : players) {
        std::cout << player.name
                  << " level: " << player.level
                  << " hp: " << player.hp
                  << std::endl;
    }
}

std::optional<std::size_t> find_player_index(const std::vector<Player>& players,
                                             const std::string& name) {
    for (std::size_t i = 0; i < players.size(); ++i) {
        if (players[i].name == name) {
            return i;
        }
    }

    return std::nullopt;
}

void print_search_result(const std::vector<Player>& players, const std::string& name) {
    std::optional<std::size_t> maybe_index = find_player_index(players, name);

    if (!maybe_index.has_value()) {
        std::cout << name << " not found" << std::endl;
        return;
    }

    const Player& player = players[*maybe_index];
    std::cout << "found " << player.name
              << " at index " << *maybe_index
              << std::endl;
}

void apply_action(std::vector<Player>& players, const GameAction& action) {
    if (std::holds_alternative<DamageAction>(action)) {
        const DamageAction& damage = std::get<DamageAction>(action);
        std::optional<std::size_t> maybe_index = find_player_index(players, damage.target_name);

        if (!maybe_index.has_value()) {
            std::cout << "damage target not found: " << damage.target_name << std::endl;
            return;
        }

        players[*maybe_index].hp -= damage.amount;
        return;
    }

    if (std::holds_alternative<HealAction>(action)) {
        const HealAction& heal = std::get<HealAction>(action);
        std::optional<std::size_t> maybe_index = find_player_index(players, heal.target_name);

        if (!maybe_index.has_value()) {
            std::cout << "heal target not found: " << heal.target_name << std::endl;
            return;
        }

        players[*maybe_index].hp += heal.amount;
        return;
    }

    if (std::holds_alternative<LevelUpAction>(action)) {
        const LevelUpAction& level = std::get<LevelUpAction>(action);
        std::optional<std::size_t> maybe_index = find_player_index(players, level.target_name);

        if (!maybe_index.has_value()) {
            std::cout << "level target not found: " << level.target_name << std::endl;
            return;
        }

        players[*maybe_index].level += level.levels;
        return;
    }

    const ChatMessage& message = std::get<ChatMessage>(action);
    std::cout << "message: " << message.text << std::endl;
}

int main() {
    std::vector<Player> players = {
        {"Alice", 3, 80},
        {"Bob", 2, 70},
        {"Charlie", 5, 95},
    };

    std::cout << "original players:" << std::endl;
    print_players(players);

    std::cout << "optional demo:" << std::endl;
    print_search_result(players, "Bob");
    print_search_result(players, "Diana");

    std::cout << "variant demo:" << std::endl;
    std::vector<GameAction> actions = {
        DamageAction{"Alice", 15},
        HealAction{"Bob", 10},
        ChatMessage{"round finished"},
        DamageAction{"Diana", 20},
        LevelUpAction{"Alice", 20}
    };

    for (const auto& action : actions) {
        apply_action(players, action);
    }

    std::cout << "players after actions:" << std::endl;
    print_players(players);

    return 0;
}

/*
练习答案写在这里：
练习1:
1.表示可能返回size_t,也可能没有值
2.表示没有值
3.因为-1语义不明确，size_t表示下标，用-1类型也不对
练习2:
1.因为不确定是否返回了值
2.取出值
3.会出现未定义行为
练习3:
1.四种动作
2.不能
3.因为会出现它属于某一类型，但是无关类型被污染的一个情况
练习4:
1.Alice的level变了
练习5:
1.适合解决可能找不到值这种类似的场景
2.适合解决一个值可能是固定类型之一
3.应该考虑`optional<std::size_t>`，适合用来表示找不到下标，也满足下标的范围
*/
