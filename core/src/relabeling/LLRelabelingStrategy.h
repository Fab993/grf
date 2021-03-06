/*-------------------------------------------------------------------------------
  This file is part of generalized random forest (grf).

  grf is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  grf is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with grf. If not, see <http://www.gnu.org/licenses/>.
 #-------------------------------------------------------------------------------*/

#ifndef GRF_LLRELABELINGSTRATEGY_H
#define GRF_LLRELABELINGSTRATEGY_H

#include "relabeling/RelabelingStrategy.h"
#include "Eigen/Dense"

namespace grf {

class LLRelabelingStrategy final: public RelabelingStrategy {
public:
  LLRelabelingStrategy(double split_lambda,
                       bool weight_penalty,
                       std::vector<double> overall_beta,
                       size_t ll_split_cutoff,
                       std::vector<size_t> ll_split_variables);
  bool relabel(
      const std::vector<size_t>& samples,
      const Data& data,
      std::vector<double>& responses_by_sample) const;
private:
    double split_lambda;
    bool weight_penalty;
    std::vector<double> overall_beta;
    size_t ll_split_cutoff;
    std::vector<size_t> ll_split_variables;
};

} // namespace grf

#endif //GRF_LLRELABELINGSTRATEGY_H
