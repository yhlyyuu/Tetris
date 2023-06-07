#include "Board.h"

// Board 類別的建構子，初始化棋盤的寬度和高度
Board::Board(int width, int height)
    : width{ width }, height{ height } {
    // 建立所有可能的移動點並加入到 all_points 向量中
    for (int i{ 0 }; i < width; i++)
        for (int j{ 0 }; j < height; j++)
            all_points.push_back(Move(i, j));

    // 設定邊界
    set_border();
}

// 重新設定棋盤，包括邊界和已建立的點
void Board::refresh() {
    set_border(); // 設定邊界
    // 將已建立的點加入到所有點中，並將所有點中與已建立的點相同的點設定為已建立的點
    for (auto& all_pnt : all_points)
        for (auto built_pnt : built_points)
            if (all_pnt == built_pnt)
                all_pnt = built_pnt; // 設定 all_pnt 的字元為 built_pnt 的字元
}

// 將指定的點集合插入到已建立的點中
void Board::insert_to_built_points(std::vector<Move> insert_points) {
    built_points.insert(built_points.end(), insert_points.begin(), insert_points.end());
}

// 設定棋盤的邊界
void Board::set_border() {
    for (auto& point : all_points) {
        // 如果點的 x 或 y 等於 0，或者點的 x 或 y 等於寬度或高度減去 1，則將點的類型設為 '#'
        if (point.get_x() == 0 || point.get_y() == 0 || point.get_x() == width - 1 || point.get_y() == height - 1)
            point.set_type('#');
        else
            point.set_type(' '); // 否則將點的類型設為 ' '
    }
}

// 移除棋盤上的行，並返回移除的行數
int Board::remove_row() {
    int removed_rows{ 0 };
    int i{ 1 };
    while (i < height) {
        // 計算位於第 i 列的已建立的點的數量
        int built_points_count = std::count_if(built_points.begin(), built_points.end(), [i](const Move& point) {
            return (point.get_y() == i);
            });

        // 如果第 i 列的已建立的點的數量等於寬度減去 2
        if (built_points_count == (width - 2)) {
            removed_rows++; // 移除的行數加 1

            // 使用 erase-remove idiom 從已建立的點中移除位於第 i 列的點
            auto it = std::remove_if(built_points.begin(), built_points.end(), [i](Move point) {
                return (point.get_y() == i);
                });
            built_points.erase(it, built_points.end()); // 從容器中移除元素

            // 將位於第 i 列之上的點向下移動一格
            std::for_each(built_points.begin(), built_points.end(), [i](Move& point) {
                if (point.get_y() > i)
                    point.move(0, -1);
                });
        }
        else
            i++; // 否則處理下一列
    }

    return removed_rows; // 返回移除的行數
}