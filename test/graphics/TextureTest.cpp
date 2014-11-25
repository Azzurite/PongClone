/** \file
 *
 * \date 03.12.2014
 * \author Azzurite
 *
 * \copyright GPL v3
 *   Copyright (C) 2014 Azzurite
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "graphics/Texture.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "graphics/Window.h"
#include "graphics/Renderer.h"
#include "graphics/Surface.h"

namespace pong {
namespace graphics {

// region gmock using statements

// fixture
using ::testing::Test;
// parameterized tests
using ::testing::WithParamInterface;
using ::testing::ValuesIn; // ValuesIn(container) and ValuesIn(begin, end)
using ::testing::Values; // Values(v1, v2, ..., vN)
using ::testing::Range; // Range(begin, end[, step])
using ::testing::Combine; // Combine(g1, g2, ..., gN)

// wildcard matchers
using ::testing::_; // any value
using ::testing::A; // any value of type A<type>
using ::testing::An; // any value of type An<type>

// general matchers
using ::testing::Ge; // >=
using ::testing::Gt; // >
using ::testing::Le; // <=
using ::testing::Lt; // <
using ::testing::Ne; // !=
using ::testing::IsNull; // == NULL
using ::testing::NotNull; // != NULL
using ::testing::Ref; // argument is a reference to variable.
using ::testing::TypedEq;

// floating point matchers
using ::testing::DoubleEq; // treating two NaNs as unequal.
using ::testing::FloatEq; // treating two NaNs as unequal.
using ::testing::NanSensitiveDoubleEq; // treating two NaNs as equal.
using ::testing::NanSensitiveFloatEq; // treating two NaNs as equal.

// string matchers
using ::testing::ContainsRegex;
using ::testing::EndsWith;
using ::testing::HasSubstr;
using ::testing::MatchesRegex; // full string has to match
using ::testing::StartsWith;
using ::testing::StrCaseEq; // == ignoring case.
using ::testing::StrCaseNe; // != ignoring case.
using ::testing::StrEq; // ==
using ::testing::StrNe; // !=

// container matchers
using ::testing::ContainerEq; // The same as Eq(container) except that the failure message also includes element differences
using ::testing::Contains; // argument contains an element that matches e, which can be either a value or a matcher. 
using ::testing::Each; // argument is a container where every element matches e, which can be either a value or a matcher. 
using ::testing::ElementsAre; // 0 to 10 arguments are allowed. 
using ::testing::ElementsAreArray; // initializer list, STL-style container, or C-style array. 
using ::testing::IsEmpty;
using ::testing::SizeIs; // SizeIs(matcher)
using ::testing::UnorderedElementsAre; // same as ElementsAre, except unordered
using ::testing::UnorderedElementsAreArray; // same as ElementsAreArray, except unordered

// composite
using ::testing::AllOf; // all
using ::testing::AnyOf; // at least one
using ::testing::Not;

// actions
using ::testing::DoDefault;
// returning
using ::testing::Return; // Return() for void or Return(value)
using ::testing::ReturnArg; // ReturnArg<N>()	Return the N-th (0-based) argument.
using ::testing::ReturnNew;
using ::testing::ReturnNull;
using ::testing::ReturnPointee;
using ::testing::ReturnRef;
using ::testing::ReturnRefOfCopy;
// side effects
using ::testing::Assign; // Assign(&variable, value)
using ::testing::DeleteArg; // Delete the N-th (0-based) argument, which must be a pointer. 
using ::testing::SaveArg; // SaveArg<N>(pointer) Save the N-th (0-based) argument to *pointer. 
using ::testing::SaveArgPointee; // SaveArgPointee<N>(pointer) 	Save the value pointed to by the N-th (0-based) argument to *pointer. 
using ::testing::SetArgReferee; // SetArgReferee<N>(value) Assign value to the variable referenced by the N-th (0-based) argument. 
using ::testing::SetArgPointee; // SetArgPointee<N>(value) Assign value to the variable pointed by the N-th (0-based) argument.
using ::testing::SetArrayArgument; // SetArrayArgument<N>(first, last)
using ::testing::Throw;
// function as action
using ::testing::Invoke; // Invoke(f), f = function; Invoke(object_pointer, &class::method) invokes with args
using ::testing::InvokeWithoutArgs; // same as Invoke, except no arguments passed
using ::testing::InvokeArgument; // InvokeArgument<N>(arg1, arg2, ..., argk), invokes an argument that is a function
// composite
using ::testing::DoAll; // DoAll(a1, a2, ..., an), only an may return a value
using ::testing::IgnoreResult; // a must not return void.
using ::testing::WithArg; // WithArg<N>(a) Pass the N-th (0-based) argument of the mock function to action a and perform it.
using ::testing::WithArgs; // WithArgs<N1, N2, ..., Nk>(a) same as WithArg
using ::testing::WithoutArgs; // WithoutArgs(a) Perform action a without any arguments.

// cardinalities (in the Times() function)
using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::AtMost;
using ::testing::Between;
// endregion

class TextureTest_UsesSDL : public Test
{
public:

	TextureTest_UsesSDL() : w("Test"), r(w.createRenderer(false)), s("P:\\data\\test\\momo.bmp")
	{
	}
	virtual void SetUp()
	{
	}

	virtual ~TextureTest_UsesSDL()
	{
	}
	virtual void TearDown()
	{
	}

	Window w;
	Renderer r;
	Surface s;
};

TEST_F(TextureTest_UsesSDL, Default)
{
}

}} // namespace pong::graphics
