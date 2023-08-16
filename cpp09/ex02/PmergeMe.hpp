/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerzak <rmerzak@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:04:29 by rmerzak           #+#    #+#             */
/*   Updated: 2023/08/16 18:32:33 by rmerzak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
class PmergeMe
{
private:
std::vector<int> Pmerge;
public:
    PmergeMe(char **argv);
    ~PmergeMe();
    std::vector<int> merge_insertion_sort(const std::vector<int> &A);
    std::vector<int> create_s(const std::vector<std::pair<int, int> > &sorted_split_array, int straggler);
    int binary_search_insertion_index(const std::vector<int> &sorted_array, int value);
    void sort_by_larger_value(std::vector<std::pair<int, int> > &sorted_split_array);
    std::vector<int> build_jacob_insertion_sequence(int array_len);
    int jacobsthal_memoized(int n);
    void insertion_sort_pairs(std::vector<std::pair<int, int> > &A, int n);
    void insert(std::pair<int, int> element, std::vector<std::pair<int, int> > &A, int n);
    std::vector<std::pair<int, int> > sort_each_pair(const std::vector<std::pair<int, int> > &split_array);
    std::vector<std::pair<int, int> > create_pairs(const std::vector<int> &a);
};