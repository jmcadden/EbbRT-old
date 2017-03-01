//          Copyright Boston University SESA Group 2013 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef HOSTED_SRC_INCLUDE_EBBRT_POOLALLOCATOR_H_
#define HOSTED_SRC_INCLUDE_EBBRT_POOLALLOCATOR_H_

#include <string>

#include "../StaticSharedEbb.h"
#include "EbbRef.h"
#include "Messenger.h"
#include "StaticIds.h"
#include "NodeAllocator.h"

namespace ebbrt {
  class PoolAllocator : public StaticSharedEbb<PoolAllocator> {
    private:
      ebbrt::Messenger::NetworkId * nids_;
      int num_nodes_;
      std::atomic<int> num_nodes_alloc_;
      std::string binary_path_;
      ebbrt::Promise<void> pool_promise_;

    public:
      void AllocatePool(std::string binary_path, int numNodes);
      void AllocateNode(int i);
      ebbrt::NodeAllocator::NodeDescriptor GetNodeDescriptor(int i);
      ebbrt::Messenger::NetworkId GetNidAt(int i) { return nids_[i];};
      ebbrt::Future<void> waitPool() { return std::move(pool_promise_.GetFuture()); }
  };
  const constexpr auto pool_allocator = EbbRef<PoolAllocator>(kPoolAllocatorId);
}
#endif  // HOSTED_SRC_INCLUDE_EBBRT_POOLALLOCATOR_H_
