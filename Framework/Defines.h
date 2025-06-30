#pragma once

// Defines.h

enum class Origins
{
	TL, TC, TR, // 0 1 2
	ML, MC, MR, // 3 4 5
	BL, BC, BR, // 6 7 8
	Custom		// 9
};

enum class SceneIds
{
	None = -1,
	Game,
	Dev1,
	Dev2,
	Count // 이런식으로 많이 사용
};

enum class Sides
{
	Left,
	Right,
	None
};