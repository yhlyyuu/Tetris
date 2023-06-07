#include "Board.h"

// Board ���O���غc�l�A��l�ƴѽL���e�שM����
Board::Board(int width, int height)
    : width{ width }, height{ height } {
    // �إߩҦ��i�઺�����I�å[�J�� all_points �V�q��
    for (int i{ 0 }; i < width; i++)
        for (int j{ 0 }; j < height; j++)
            all_points.push_back(Move(i, j));

    // �]�w���
    set_border();
}

// ���s�]�w�ѽL�A�]�A��ɩM�w�إߪ��I
void Board::refresh() {
    set_border(); // �]�w���
    // �N�w�إߪ��I�[�J��Ҧ��I���A�ñN�Ҧ��I���P�w�إߪ��I�ۦP���I�]�w���w�إߪ��I
    for (auto& all_pnt : all_points)
        for (auto built_pnt : built_points)
            if (all_pnt == built_pnt)
                all_pnt = built_pnt; // �]�w all_pnt ���r���� built_pnt ���r��
}

// �N���w���I���X���J��w�إߪ��I��
void Board::insert_to_built_points(std::vector<Move> insert_points) {
    built_points.insert(built_points.end(), insert_points.begin(), insert_points.end());
}

// �]�w�ѽL�����
void Board::set_border() {
    for (auto& point : all_points) {
        // �p�G�I�� x �� y ���� 0�A�Ϊ��I�� x �� y ����e�שΰ��״�h 1�A�h�N�I�������]�� '#'
        if (point.get_x() == 0 || point.get_y() == 0 || point.get_x() == width - 1 || point.get_y() == height - 1)
            point.set_type('#');
        else
            point.set_type(' '); // �_�h�N�I�������]�� ' '
    }
}

// �����ѽL�W����A�ê�^���������
int Board::remove_row() {
    int removed_rows{ 0 };
    int i{ 1 };
    while (i < height) {
        // �p����� i �C���w�إߪ��I���ƶq
        int built_points_count = std::count_if(built_points.begin(), built_points.end(), [i](const Move& point) {
            return (point.get_y() == i);
            });

        // �p�G�� i �C���w�إߪ��I���ƶq����e�״�h 2
        if (built_points_count == (width - 2)) {
            removed_rows++; // ��������ƥ[ 1

            // �ϥ� erase-remove idiom �q�w�إߪ��I���������� i �C���I
            auto it = std::remove_if(built_points.begin(), built_points.end(), [i](Move point) {
                return (point.get_y() == i);
                });
            built_points.erase(it, built_points.end()); // �q�e������������

            // �N���� i �C���W���I�V�U���ʤ@��
            std::for_each(built_points.begin(), built_points.end(), [i](Move& point) {
                if (point.get_y() > i)
                    point.move(0, -1);
                });
        }
        else
            i++; // �_�h�B�z�U�@�C
    }

    return removed_rows; // ��^���������
}