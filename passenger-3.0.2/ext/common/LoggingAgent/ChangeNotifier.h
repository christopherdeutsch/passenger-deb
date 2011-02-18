/*
 *  Phusion Passenger - http://www.modrails.com/
 *  Copyright (c) 2010 Phusion
 *
 *  "Phusion Passenger" is a trademark of Hongli Lai & Ninh Bui.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 */
#ifndef _PASSENGER_CHANGE_NOTIFIER_H_
#define _PASSENGER_CHANGE_NOTIFIER_H_

#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
#include <ev++.h>
#include "DataStoreId.h"
#include "../EventedClient.h"
#include "../FileDescriptor.h"
#include "../StaticString.h"

namespace Passenger {

using namespace std;
using namespace boost;


class ChangeNotifier {
public:
	typedef function<string (const StaticString &groupName, const StaticString &nodeName,
		const StaticString &category)> GetLastPosFunction;
	
	GetLastPosFunction getLastPos;
	
	ChangeNotifier(struct ev_loop *_loop) { }
	virtual ~ChangeNotifier() { }
	
	virtual void addClient(const FileDescriptor &fd) { }
	
	virtual void changed(const DataStoreId &dataStoreId) { }
};

typedef shared_ptr<ChangeNotifier> ChangeNotifierPtr;


} // namespace Passenger

#endif /* _PASSENGER_CHANGE_NOTIFIER_H_ */
