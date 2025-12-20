#pragma once

namespace ppt::vis
{
	class IShape
	{
	public:
		virtual ~IShape() = default;
		virtual void draw() const = 0;
	};
}
