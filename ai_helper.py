import sys
import json
import urllib.request
import os

def fallback_ai(prompt):
    prompt = prompt.lower()
    if "kill" in prompt and "name" in prompt:
        return "pkill <process_name>"
    elif "process" in prompt or "running" in prompt:
        return "ps aux"
    elif "c files" in prompt:
        return 'find . -name "*.c" -mtime 0'
    elif "memory" in prompt:
        return "free -m"
    elif "ip" in prompt or "network" in prompt:
        return "ip a"
    else:
        return "echo 'Command not found in AI fallback database'"

def main():
    if len(sys.argv) < 2:
        return

    prompt = sys.argv[1]
    raw_key = os.environ.get("GEMINI_API_KEY", "")
    api_key = raw_key.replace('"', '').replace("'", "").strip()
    
    if not api_key:
        print(fallback_ai(prompt))
        return

    url = f"https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key={api_key}"
    data = {
        "contents": [{
            "parts": [{"text": f"Output ONLY a single valid Linux shell command for this request. No markdown, no backticks, no explanation. Request: {prompt}"}]
        }]
    }

    req = urllib.request.Request(url, data=json.dumps(data).encode('utf-8'), method='POST')
    req.add_header('Content-Type', 'application/json')

    try:
        with urllib.request.urlopen(req) as response:
            result = json.loads(response.read().decode('utf-8'))
            print(result['candidates'][0]['content']['parts'][0]['text'].strip())
    except Exception:
        print(fallback_ai(prompt))

if __name__ == "__main__":
    main()
