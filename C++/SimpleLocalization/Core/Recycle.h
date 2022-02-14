#ifndef HIVE_RECYCLE_H
#define HIVE_RECYCLE_H

namespace hive
{
template <typename Type>
class Recycle
{
public:
	Recycle():_pos(0) {};

	~Recycle()
	{
		_array.RemoveAll();
	}

	Type* operator[] ( uint iIndex )
	{
		if ( iIndex < _pos )
		{
			return _array[iIndex];
		}
		else
		{
			return NULL;
		}
	}

	uint Size()
	{
		return _pos;
	}

	void Insert( Type* item, uint iIndex )
	{
		if ( iIndex < _pos )
		{
			if ( _pos < _array.Size() )
			{
				// shift right
				for(uint i = _pos; i > iIndex; i--)
				{
					_array.Swap( i, i - 1 );
				}
				_array[iIndex] = item;
				_pos++;
			}
			else
			{
				_array.PushBack( item );
			}
		}
		else
		{
			iIndex = _pos;
			PushBack( item );
		}
	}

	void Remove( uint iIndex )
	{
		if ( iIndex < _pos )
		{
			// shift left
			for(uint i = iIndex; i < _pos - 1; i++)
			{
				_array.Swap( i, i + 1 );
			}
			_pos--;
		}
	}

	void PushBack( Type* item )
	{
		if ( _pos < _array.Size() )
		{
			_array[_pos] = item;
		}
		else
		{
			_array.PushBack( item );
		}
		_pos++;
	}

	void PopBack()
	{
		if ( _pos != 0 )
		{
			_pos--;
		}
	}

	void RemoveAll()
	{
		_pos = 0;
	}

	Type* GetRecycled()
	{
		if ( _pos < _array.Size() )
		{
			return _array[_pos];
		}
		else
		{
			return NULL;
		}
	}

private:
	Array<Type*> _array;
	uint _pos;
};

} // End of namespace hive

#endif // End of HIVE_RECYCLE_H