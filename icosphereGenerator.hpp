#ifndef ICOSPHERE_GENERATOR_HPP
#define ICOSPHERE_GENERATOR_HPP
#include <vector>

namespace IcosphereGenerator {

class Icosphere{
private:
	void insertVertex(std::vector<float>* vertices, float x, float y, float z)
	{
		vertices->push_back(x);
		vertices->push_back(y);
		vertices->push_back(z);
		vertices->push_back(0.0f);
		vertices->push_back(0.0f);
		vertices->push_back(0.0f);
	}
	
	void addTriangle(std::vector<unsigned int>* indices, unsigned int a, unsigned int b, unsigned int c)
	{
		indices->push_back(a);
		indices->push_back(b);
		indices->push_back(c);
	}


public:
	std::vector<float> vertices;
	std::vector<unsigned int> indices;
	int samples;
    Icosphere(int samples_)
	{
		samples = samples_;
	}
	
	void generate()
	{
		float triangleSideLength = 1 / pow(2.0, (double)samples); 

		unsigned int meshStartingIndex = vertices.size();

		int nSideTriangles = pow(2.0, (double)samples);

		//samples > 0
		for (int iy = -nSideTriangles; iy <= 0; iy++)
		{
			int from  = -nSideTriangles + abs(iy);
			int to = abs(from);
			
			for (int ix = from; ix <= to; ix++)
			{
				float x = (float)ix* triangleSideLength;
				float y = (float)iy* triangleSideLength;

				float z = x + y + 1;
				if(ix>0)
					z = -x + y + 1;
				insertVertex(&vertices, x, z,y);
			}
			
			for (int ix = from+1; ix <= to-1; ix++)
			{
				float x = (float)ix * triangleSideLength;
				float y = (float)iy * triangleSideLength;

				float z = -x - y - 1;
				if (ix > 0)
					z = x - y - 1;

				insertVertex(&vertices, x, z, y);
			}
		}

		for (int iy = 1; iy <= nSideTriangles; iy++)
		{
			int from = -nSideTriangles + abs(iy);
			int to = abs(from);

			for (int ix = from; ix <= to; ix++)
			{
				float x = (float)ix * triangleSideLength;
				float y = (float)iy * triangleSideLength;
				
				float z = x - y + 1;
				if (ix > 0)
					z = -x - y + 1;
				
				insertVertex(&vertices, x, z, y);
			}

			for (int ix = from + 1; ix <= to - 1; ix++)
			{
				float x = (float)ix * triangleSideLength;
				float y = (float)iy * triangleSideLength;
				float z = -x + y - 1;
				if (ix > 0)
					z = x + y - 1;
				insertVertex(&vertices, x, z, y);
			}
		}

		
		std::vector<int> list;
		
		list.resize(nSideTriangles*2+1);

		
		int previousIndex = 1;
		int currentIndex = 0;
		for (int iy = 1; iy < nSideTriangles +1+1; iy++)
		{   
			currentIndex = previousIndex + 4 * (iy-1);
			list[iy] = currentIndex;
			previousIndex = currentIndex;
		}

		for (int iy = 1; iy < nSideTriangles; iy++)
		{
			float diff = list[(nSideTriangles+2) - iy-1] - list[(nSideTriangles+1) - iy-1];
			list[(nSideTriangles + 1) + iy] = diff + list[(nSideTriangles + 1) + iy - 1];

		}
		


		//topleft
		for (int iy = 1; iy < nSideTriangles + 1; iy++)
		{
			int prevStartingIndex = list[iy - 1];
			int currStartingIndex = list[iy];

			//topleft
			for (int ix = 0; ix < iy; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix;
				int bottomCurrentIndex = currStartingIndex + ix;
				addTriangle(&indices, topCurrentIndex, bottomCurrentIndex, bottomCurrentIndex + 1);


				if (ix == 0)
				{
					addTriangle(&indices, topCurrentIndex, bottomCurrentIndex, bottomCurrentIndex + (iy)*2 + 1);
				}
				else
				{
					addTriangle(&indices, topCurrentIndex+ (iy-1) * 2, bottomCurrentIndex + iy * 2, bottomCurrentIndex + iy * 2 + 1);
				}
			}

			for (int ix = 0; ix < iy - 1; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix;
				int bottomCurrentIndex = currStartingIndex + ix;
				addTriangle(&indices, topCurrentIndex, topCurrentIndex + 1, bottomCurrentIndex + 1);

				if (ix == 0)
				{
					addTriangle(&indices, topCurrentIndex, topCurrentIndex + (iy-1) * 2 + 1, bottomCurrentIndex + (iy) * 2 + 1);
				}
				else
				{
					addTriangle(&indices, topCurrentIndex + (iy - 1) * 2, topCurrentIndex + (iy - 1) * 2+1, bottomCurrentIndex + iy * 2 + 1);
				}
			}

			//topright
			for (int ix = 0; ix < iy; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix + iy - 1;
				int bottomCurrentIndex = currStartingIndex + ix + iy;
				addTriangle(&indices, topCurrentIndex, bottomCurrentIndex, bottomCurrentIndex + 1);

				if (ix == iy-1)
				{
					addTriangle(&indices, topCurrentIndex, bottomCurrentIndex + (iy) * 2 , bottomCurrentIndex + 1);
				}
				else
				{
					addTriangle(&indices, topCurrentIndex + (iy - 1) * 2, bottomCurrentIndex + iy * 2, bottomCurrentIndex + iy * 2 + 1);
				}
			}

			for (int ix = 0; ix < iy - 1; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix + iy - 1;
				int bottomCurrentIndex = currStartingIndex + ix + iy;
				addTriangle(&indices, topCurrentIndex, topCurrentIndex + 1, bottomCurrentIndex + 1);

				if (ix == iy - 1-1)
				{
					addTriangle(&indices, topCurrentIndex + (iy-1) * 2, topCurrentIndex + 1, bottomCurrentIndex + (iy) * 2 + 1);
				}
				else
				{
					addTriangle(&indices, topCurrentIndex + (iy - 1) * 2, topCurrentIndex + (iy - 1) * 2 + 1, bottomCurrentIndex + iy * 2 + 1);
				}
			}

		}
		
		
		//bottom
		int nT = nSideTriangles;
		for (int iy = nSideTriangles; iy <  2*nSideTriangles; iy++,nT--)
		{
			int prevStartingIndex = list[iy];
			int currStartingIndex = list[iy+1];

			//bottomright
			for (int ix = 0; ix < nT; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix ;
				int bottomCurrentIndex = currStartingIndex + ix;
				addTriangle(&indices, topCurrentIndex, topCurrentIndex+1, bottomCurrentIndex);

				if (ix == 0)
				{
					addTriangle(&indices, topCurrentIndex, topCurrentIndex + (nT) * 2 + 1, bottomCurrentIndex);
				}
				else
				{
					addTriangle(&indices, topCurrentIndex + (nT) * 2, topCurrentIndex + (nT) * 2 + 1, bottomCurrentIndex + (nT-1) * 2);
				}
			}

			for (int ix = 0; ix < nT - 1; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix;
				int bottomCurrentIndex = currStartingIndex + ix;
				addTriangle(&indices, topCurrentIndex + 1, bottomCurrentIndex, bottomCurrentIndex + 1);

				if (ix == 0)
				{
					addTriangle(&indices, topCurrentIndex + (nT) * 2+1, bottomCurrentIndex, bottomCurrentIndex + (nT-1) * 2+1);
				}
				else
				{
					addTriangle(&indices, topCurrentIndex + (nT) * 2+1, bottomCurrentIndex + (nT-1) * 2 , bottomCurrentIndex + (nT - 1) * 2+1);
				}
			}


			//topright
			for (int ix = 0; ix < nT; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix + nT;
				int bottomCurrentIndex = currStartingIndex + ix + nT-1;
				addTriangle(&indices, topCurrentIndex, topCurrentIndex+1, bottomCurrentIndex);


				if (ix == nT-1)
				{
					addTriangle(&indices, topCurrentIndex  +(nT) * 2, topCurrentIndex+1, bottomCurrentIndex); // problem???
				}
				else
				{
				   addTriangle(&indices, topCurrentIndex + (nT) * 2, topCurrentIndex  + nT * 2 + 1, bottomCurrentIndex + (nT-1) * 2);
				}
			}

			for (int ix = 0; ix < nT - 1; ix++)
			{
				int topCurrentIndex = prevStartingIndex + ix + nT;
				int bottomCurrentIndex = currStartingIndex + ix + nT-1;
				addTriangle(&indices, topCurrentIndex+1, bottomCurrentIndex, bottomCurrentIndex + 1);

				if (ix == nT-2)
				{
					addTriangle(&indices, topCurrentIndex + (nT) * 2 + 1, bottomCurrentIndex + (nT - 1) * 2, bottomCurrentIndex+1); // problem???
				}
				else
				{
					addTriangle(&indices, topCurrentIndex + (nT) * 2+1, bottomCurrentIndex + (nT-1) * 2, bottomCurrentIndex + (nT - 1) * 2 + 1);
				}
			}

		}
	}
		
	~Icosphere()
	{
		vertices.clear();
		vertices.shrink_to_fit();
		
		indices.clear();
		indices.shrink_to_fit();
	}
};


} // namespace IcosphereGenerator

#endif //ICOSPHERE_GENERATOR_HPP
