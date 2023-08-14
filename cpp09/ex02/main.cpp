/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:04:32 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/14 11:47:25 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <vector>
#include <algorithm>

// Split into pairs
std::vector<std::pair<int, int> > create_pairs(const std::vector<int>& a) {
    std::vector<std::pair<int, int> > split_array;
    std::vector<int> temp_array;

    for (size_t i = 0; i < a.size(); i++) {
        size_t temp_length = temp_array.size();
        if (temp_length == 1) {
            temp_array.push_back(a[i]);
            split_array.push_back(std::make_pair(temp_array[0], temp_array[1]));
            temp_array.clear();
        // } else if (split_array.size() * 2 == a.size() - 1) {
        //     std::cout << "one time: " << a[i] << std::endl;
        //     split_array.push_back(std::make_pair(a[i], -1));
        } else if (temp_length == 0) {
            temp_array.push_back(a[i]);
        }
    }

    return split_array;
}

// Sort all the pairs
std::vector<std::pair<int, int> > sort_each_pair(const std::vector<std::pair<int, int> >& split_array) {
    std::vector<std::pair<int, int> > sorted_split_array = split_array;

    for (size_t i = 0; i < sorted_split_array.size(); i++) {
        if (sorted_split_array[i].second != -1 && sorted_split_array[i].first > sorted_split_array[i].second) {
            std::swap(sorted_split_array[i].first, sorted_split_array[i].second);
        }
    }

    return sorted_split_array;
}

// Recursive insertion sort by highest value in pair
void insert(std::pair<int, int> element, std::vector<std::pair<int, int> >& A, int n) {
    if (n < 0) {
        A[0] = element;
    } else if (element.second >= A[n].second) {
        if (n == static_cast<int>(A.size()) - 1) {
            A.push_back(element);
        } else {
            A[n + 1] = element;
        }
    } else {
        if (n == static_cast<int>(A.size()) - 1) {
            A.push_back(A[n]);
        } else {
            A[n + 1] = A[n];
            insert(element, A, n - 1);
        }
    }
}

// Entry function to recursively sort pairs by their higher value
std::vector<std::pair<int, int> >insertion_sort_pairs(std::vector<std::pair<int, int> >& A, int n) {
    if (n < 1) {
        return A;
    } else {
        insertion_sort_pairs(A, n - 1);
        insert(A[n], A, n - 1);
    }
};

// Recursive function to generate nth Jacobsthal number
int jacobsthal(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Build a sequence of valid Jacobsthal numbers, given an array length
std::vector<int> build_jacob_insertion_sequence(const std::vector<int>& array) {
    std::vector<int> end_sequence;
    int array_len = array.size();
    int jacob_index = 3;

    std::cout << "Jacobsthal Sequence:" << std::endl;
    std::cout << "array_len: " << array_len << std::endl;
        std::cout << "jacob: " << jacobsthal(array_len) << std::endl;
    while (jacobsthal(jacob_index) < array_len - 1) {
        end_sequence.push_back(jacobsthal(jacob_index));
        jacob_index = jacob_index + 1;
    }

    return end_sequence;
}

// Recursively sort the larger set of elements into sorted set
void sort_by_larger_value(std::vector<std::pair<int, int> >& sorted_split_array) {
    insertion_sort_pairs(sorted_split_array, sorted_split_array.size() - 1);
}

// Create Sequence
std::vector<int> create_s(const std::vector<std::pair<int, int> >& sorted_split_array, int straggler, bool print_comparison_estimation) {
    std::vector<int> S;
    std::vector<int> pend;

    int comparisons_made = 0;

    for (size_t i = 0; i < sorted_split_array.size(); i++) {
        S.push_back(sorted_split_array[i].second);
        pend.push_back(sorted_split_array[i].first);
    }

    S.insert(S.begin(), pend[0]);
    // print pend vector
    std::cout << "P--------------" << std::endl;
    for (size_t i = 0; i < pend.size(); i++) {
        std::cout << pend[i] << "-";
    }
    std::cout << std::endl;
    std::cout <<"P--------------" <<std::endl;
    // print S vector
    std::cout << "--------------" << std::endl;
    for (size_t i = 0; i < S.size(); i++) {
        std::cout << S[i] << "-";
    }
    std::cout << std::endl;
    std::cout <<"--------------" <<std::endl;

    int iterator = 0;
    int jacob_index = 3;
    std::vector<int> indexSequence;
    std::string last = "default";

    std::vector<int> jacob_insertion_sequence = build_jacob_insertion_sequence(pend);
    // print jacob_insertion_sequence vector
    std::cout << "j--------------" << std::endl;
    for (size_t i = 0; i < jacob_insertion_sequence.size(); i++) {
        std::cout << jacob_insertion_sequence[i] << "-";
    }
    std::cout << std::endl;
    std::cout <<"j--------------" <<std::endl;
    while (iterator <= static_cast<int>(pend.size())) {
        int item = 0;
        if (!jacob_insertion_sequence.empty() && last != "jacob") {
            std::cout << "jacob_insertion: "<< std::endl;
            indexSequence.push_back(jacob_insertion_sequence[0]);
            item = pend[jacob_insertion_sequence[0] - 1];
            jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
            last = "jacob";
        } else {
            std::cout << "not-jacob_insertion: "<< std::endl;
            if (std::find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end()) {
                iterator++;
            }
            item = pend[iterator - 1];
            indexSequence.push_back(iterator);
            last = "not-jacob";
        }

        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), item);
        S.insert(insertion_point, item);
        std::cout << "not-jacob_insertion: "<< std::endl;
        iterator++;
        jacob_index++;
    }

    if (straggler) {
        std::vector<int>::iterator insertion_point = std::lower_bound(S.begin(), S.end(), straggler);
        S.insert(insertion_point, straggler);
        comparisons_made += 2;
    }

    if (print_comparison_estimation) {
        std::cout << "Approximate Comparisons Made:" << std::endl;
        std::cout << comparisons_made << std::endl;
    }

    return S;
}

// Ford-Johnson Merge-Insertion Sort
std::vector<int> merge_insertion_sort(const std::vector<int>& A) {
    std::cout << "Starting Array:" << std::endl;
    for (size_t i = 0; i < A.size(); i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    bool hasStraggler = A.size() % 2 != 0;
    int straggler = -1;

    if (hasStraggler) {
        straggler = A[A.size() - 1];
    }

    std::vector<std::pair<int, int> > split_array = create_pairs(A);
    // ptint split_array vector
    for(size_t i = 0; i < split_array.size(); i++) {
        std::cout <<" split array " <<split_array[i].first << " " << split_array[i].second << std::endl;
    }
    std::vector<std::pair<int, int> > sorted_split_array = sort_each_pair(split_array);
     for(size_t i = 0; i < sorted_split_array.size(); i++) {
        std::cout <<"0 sorted split array " <<sorted_split_array[i].first << " " << sorted_split_array[i].second << std::endl;
    }
    sort_by_larger_value(sorted_split_array);

    for(size_t i = 0; i < sorted_split_array.size(); i++) {
        std::cout <<"1 sorted split array " <<sorted_split_array[i].first << " " << sorted_split_array[i].second << std::endl;
    }
    std::vector<int> S = create_s(sorted_split_array, straggler, true);

    std::cout << "Sorted Array:" << std::endl;
    // ptint S vector
    for (size_t i = 0; i < S.size(); i++) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;
    return S;
}

int main() {
    std::vector<int> a;

    for (int i = 0; i < 12; i++) {
        int randomNumber = rand() % 500;
        a.push_back(randomNumber);
    }

    merge_insertion_sort(a);

    return 0;
}
