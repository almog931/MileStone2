

#ifndef MILESTONE2_SEARCHABLEMATRIX_H
#define MILESTONE2_SEARCHABLEMATRIX_H

#include "Searchable.h"


/*
 * This class is searchable.
 * Its matrix that we can find path from some initial node
 * to the goal node who declared to us.
 */
class SearchableMatrix : public Searchable<std::pair<int, int>> {

    std::vector<std::vector<State<std::pair<int, int>> *> *> *stateMatrix;
    int row;
    int col;

public:

    SearchableMatrix(std::pair<int, int> initial, std::pair<int, int> goal, std::vector<std::vector<double> *> *matrix,
                     int row, int col) {
        this->row = row;
        this->col = col;
        stateMatrix = setStatesMatrix(matrix);
        initAndGoal(initial, goal);

    }

    void initAndGoal(std::pair<int, int> init, std::pair<int, int> goal);

    virtual std::vector<State<std::pair<int, int>> *> *getPossibleStates(State<std::pair<int, int>> *state);

    virtual std::vector<State<std::pair<int, int>> *> *getAllStates();

    virtual State<std::pair<int, int>> *getInitial();

    virtual State<std::pair<int, int>> *getGoal();

    std::vector<std::vector<State<std::pair<int, int>> *> *> *
    setStatesMatrix(std::vector<std::vector<double> *> *matrix);

    virtual void setDistance(State<std::pair<int, int>> *state, State<std::pair<int, int>> *goal);

    //deletes the matrix states and the two vectors.

    ~SearchableMatrix() {
        for (auto vec: *stateMatrix) {
            for (auto state: *vec) {
                delete (state);
            }
            delete (vec);
        }
        delete (stateMatrix);
    }

};


#endif //MILESTONE2_SEARCHABLEMATRIX_H
