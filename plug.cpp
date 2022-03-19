#include "plug.h"

#pragma mark - Constructor
plugboard::plugboard()
{
    reset();
}

#pragma mark - Utilities
void plugboard::reset()
{
    for (int i = 0; i < 26; i++)
    {
        m_mappings[i] = i;
    }
}

int plugboard::index(char c)
{
    if (!isalpha(c))
        throw std::runtime_error("Lowercase or uppercase ASCII character expected.");
    char c_norm = toupper(c);
    return c_norm - ASCII_START;
}

#pragma mark - Accessors
void plugboard::set(char c, char d)
{
    int c_idx = index(c);
    int d_idx = index(d);
    remove(c);
    remove(d);
    m_mappings[c_idx] = d_idx;
    m_mappings[d_idx] = c_idx;
}

void plugboard::remove(char c)
{
    int c_idx = index(c);
    if (m_mappings[c_idx] != c_idx)
    {
        int temp = m_mappings[c_idx];
        m_mappings[m_mappings[c_idx]] = temp;
        m_mappings[c_idx] = c_idx;
    }
}

#pragma mark - Encoding
char plugboard::encode(char c)
{
    int c_idx = index(c);
    if (this->m_mappings[c_idx] == c_idx)
    {
        return c;
    }
    else
    {
        return ASCII_START + m_mappings[c_idx];
    }
}
