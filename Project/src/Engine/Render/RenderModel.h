#ifndef _RENDER_MODEL_H
#define _RENDER_MODEL_H

class RenderModel {
public:
	static RenderModel & GetInstance() {
		static RenderModel singleton;
		return singleton;
	}
private:
	RenderModel() {}
};

#endif
